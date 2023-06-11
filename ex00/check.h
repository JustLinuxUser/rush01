/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adokhnia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:42:30 by adokhnia          #+#    #+#             */
/*   Updated: 2023/06/11 23:42:32 by adokhnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 4

void	zero_out_N_N(int arr[N][N], int x, int y)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (row < y)
	{
		while (col < x)
		{
			arr[row][col] = 0;
			col++;
		}
		row++;
	}
}

void	zero_out_4_N(int arr[4][N], int x, int y)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (row < y)
	{
		while (col < x)
		{
			arr[row][col] = 0;
			col++;
		}
		row++;
	}
}

void	zero_out_single(int arr[N], int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		arr[col] = 0;
		col++;
	}
}
int	check_left_to_righ(int fields[N][N], int sums[4][N], int row)
{
	int	column;
	int	current_can_see;
	int	highest;

	current_can_see = 0;
	highest = 0;
	column = 0;
	while (column < N)
	{
		if (fields[row][column] > highest)
		{
			highest = fields[row][column];
			current_can_see++;
		}
		column++;
	}
	if (current_can_see != sums[2][row])
		return (-1);
	return (0);
}

int	check_right_to_left(int fields[N][N], int sums[4][N], int row)
{
	int	column;
	int	current_can_see;
	int	highest;

	current_can_see = 0;
	highest = 0;
	column = N - 1;
	while (column >= 0)
	{
		if (fields[row][column] > highest)
		{
			highest = fields[row][column];
			current_can_see++;
		}
		column--;
	}
	if (current_can_see != sums[3][row])
		return (-1);
	return (0);
}

int	check_top_to_bottom(int fields[N][N], int sums[4][N], int column)
{
	int	row;
	int	current_can_see;
	int	highest;

	current_can_see = 0;
	highest = 0;
	row = 0;
	while (row < N)
	{
		if (fields[row][column] > highest)
		{
			highest = fields[row][column];
			current_can_see++;
		}
		row++;
	}
	if (current_can_see != sums[0][column])
		return (-1);
	return (0);
}

int	check_bottom_to_top(int fields[N][N], int sums[4][N], int column)
{
	int	row;
	int	current_can_see;
	int	highest;

	current_can_see = 0;
	highest = 0;
	row = N - 1;
	while (row >= 0)
	{
		if (fields[row][column] > highest)
		{
			highest = fields[row][column];
			current_can_see++;
		}
		row--;
	}
	if (current_can_see != sums[1][column])
		return (-1);
	column++;
	return (0);
}

int	check_num_horisontal(int fields[N][N], int num)
{
	int	row;
	int	column;
	int	total[N];

	zero_out_single(total, N);
	row = 0;
	while (row < N)
	{
		column = 0;
		while (column < N)
		{
			if (fields[row][column] == num)
			{
				if (fields[row][column] == total[column])
					return (-1);
				total[column] = fields[row][column];
			}
			column++;
		}
		row++;
	}
	return (0);
}

int	check_num_vertical(int fields[N][N], int num)
{
	int	row;
	int	column;
	int	total[N];

	zero_out_single(total, N);
	column = 0;
	while (column < N)
	{
		row = 0;
		while (row < N)
		{
			if (fields[row][column] == num)
			{
				if (fields[row][column] == total[row])
					return (-1);
				total[row] = fields[row][column];
			}
			row++;
		}
		column++;
	}
	return (0);
}

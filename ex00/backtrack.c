/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adokhnia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:42:21 by adokhnia          #+#    #+#             */
/*   Updated: 2023/06/11 23:42:23 by adokhnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./check.h"
#include <stdio.h>
#include <unistd.h>

void	print_error(void)
{
	write(1, "Error\n  ", 6);
}

int	handle_args(int argc, char **argv, int sums[4][N])
{
	int	arg_iter;
	int	row;
	int	column;

	arg_iter = 0;
	if (argc != 2)
	{
		print_error();
		return (-1);
	}
	row = 0;
	column = 0;
	while (arg_iter < N * 4 * 2 - 1)
	{
		if (argv[1][arg_iter] == '\0')
		{
			print_error();
			return (-1);
		}
		if (argv[1][N * 8 - 1] != '\0')
		{
			print_error();
			return (-1);
		}
		if (arg_iter % 2 == 0 && argv[1][arg_iter] >= 49
			&& argv[1][arg_iter] < 49 + N)
		{
			sums[row][column] = argv[1][arg_iter] - '0';
			column++;
			if (column == N)
			{
				column = 0;
				row++;
			}
		}
		else if (arg_iter % 2 != 1 || argv[1][arg_iter] != ' ')
		{
			print_error();
			return (-1);
		}
		arg_iter++;
	}
	return (0);
}

void	print(int fields[N][N])
{
	int		row;
	int		column;
	char	temp;

	row = 0;
	column = 0;
	while (row < N)
	{
		while (column < N)
		{
			if (fields[row][column] >= 0 && fields[row][column] <= N)
				temp = '0' + fields[row][column];
			else
				temp = '-';
			write(1, &temp, 1);
			if (column != N - 1)
				write(1, " ", 1);
			column++;
		}
		row++;
		column = 0;
		write(1, "\n ", 1);
	}
}

int	is_safe_rn(int fields[N][N], int sums[4][N], int column, int row)
{
	if (0 != check_num_vertical(fields, fields[row][column])
		|| 0 != check_num_horisontal(fields, fields[row][column]))
	{
		return (-1);
	}
	if (column == N - 1)
	{
		if (0 != check_left_to_righ(fields, sums, row)
			|| 0 != check_right_to_left(fields, sums, row))
		{
			return (-1);
		}
	}
	if (row == N - 1)
	{
		if (0 != check_top_to_bottom(fields, sums, column)
			|| 0 != check_bottom_to_top(fields, sums, column))
		{
			return (-1);
		}
	}
	return (0);
}
int	backtrack(int fields[N][N], int sums[4][N], int column, int row)
{
	int	success;
	int	num;

	num = fields[row][column];
	if (column >= N)
	{
		column = 0;
		row++;
	}
	if (0 != is_safe_rn(fields, sums, column, row))
		return (-1);
	if (row == N - 1 && column == N - 1)
	{
		return (0);
	}
	num = 1;
	column++;
	while (num <= N)
	{
		fields[row][column] = num;
		if (0 == backtrack(fields, sums, column, row))
			return (0);
		num++;
	}
	fields[row][column] = 0;
	return (-1);
}
int	main(int argc, char **argv)
{
	int	fields[N][N];
	int	sums[4][N];
	int	iter;

	iter = 0;
	zero_out_N_N(fields, N, N);
	zero_out_4_N(sums, 4, N);
	if (0 != handle_args(argc, argv, sums))
		return (-1);
	for (int i = 1; i <= N; i++)
	{
		fields[0][0] = i;
		if (0 == backtrack(fields, sums, 0, 0))
		{
			print(fields);
			return (0);
		}
	}
	print_error();
}

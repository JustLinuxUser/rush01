#define N 5
#include <stdio.h>

int	check_left_to_righ(int fields[N][N], int sums[4][N], int row)
{
	int column;
	int current_can_see;
	int highest;

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
    {
        printf("Check l2r %i %i\n", current_can_see, sums[2][row]);
		return (-1);
    }
	return (0);
}

int check_right_to_left(int fields[N][N], int sums[4][N], int row)
{
	int column;
	int current_can_see;
	int highest;

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
    {
        printf("Check r2l %i\n", current_can_see);
		return (-1);
    }
	return (0);
}

int check_top_to_bottom(int fields[N][N], int sums[4][N], int column)
{
	int row;
	int current_can_see;
	int highest;

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
    {
        printf("Check top to bottom\n");
		return (-1);
    }
	return (0);
}

int check_bottom_to_top(int fields[N][N], int sums[4][N], int column)
{
	int row;
	int current_can_see;
	int highest;

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
    {
        printf("Check bottom to top\n");
		return (-1);
    }
	column++;
	return (0);
}

int check_num_horisontal(int fields[N][N], int num)
{
	int	row;
	int	column;
	int	total[N] = {0};

	row = 0;
	while(row < N)
	{
		column = 0;
		while(column < N)
		{
			if (fields[row][column] == num)
			{
				if (fields[row][column] == total[column])
                {
                    printf("Check num horizontal\n");
					return -1;
                }
				total[column] = fields[row][column];
			}
			column++;
		}
		row++;
	}
	return (0);
}

int check_num_vertical(int fields[N][N], int num)
{
	int	row;
	int	column;
	int	total[N] = {0};

	column = 0;
	while(column < N)
	{
		row = 0;
		while(row < N)
		{
			if (fields[row][column] == num)
			{
				if (fields[row][column] == total[row])
                {
                    printf("Check num vertical\n");
					return -1;
                }
				total[row] = fields[row][column];
			}
			row++;
		}
		column++;
	}
	return (0);
}

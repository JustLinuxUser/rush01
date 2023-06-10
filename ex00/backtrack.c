#include "./check.c"
#include <stdio.h>

int backtrack(int fields[N][N], int sums[N][N], int column, int row)
{
	int success;
	int num;

	num = fields[row][column];
	if (column == 3)
	{
		if (0 != check_left_to_righ(fields, sums)
			|| 0 != check_right_to_left(fields, sums)
			|| 0 != check_top_to_bottom(fields, sums)
			|| 0 != check_bottom_to_top(fields, sums)
			|| 0 != check_num_vertical(fields, sums[column][row]))
		{

			fields[row][column] = 0;
			return -1;
		}
	}
	while (row < N)
	{
		column = 0;
		while (column < N)
		{
			printf("column: %i\n", column);
			while (num <= N)
			{
				num++;
				printf("N: %i\n", num);
				fields[row][column] = num;
				backtrack(fields, sums, column, row);
			}
			num = 1;
			column++;
		}
		row ++;
	}
	return 0;

}
int main()
{
	int fields[N][N] = {
		{1, 2, 3, 4},
		{2, 3, 4, 1},
		{3, 4, 4, 2},
		{4, 1, 2, 3}
	};
	int fields_1[N][N] = {0};
	int sums[N][N] = {
		{4, 3, 2, 1},
		{1, 2, 2, 2},
		{4, 3, 2, 1},
		{1, 2, 2, 2}

	};
	backtrack(fields_1, sums, 0, 0);
	for(int i =0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
			printf("%i ", fields_1[i][j]);
		printf("\n");
	}
}

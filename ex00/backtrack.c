#include "./check.c"
#include <stdio.h>
void print(int fields[N][N])
{
    for(int i =0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
            printf("%i ", fields[i][j]);
        printf("\n");
    }
}

int is_safe_rn(int fields[N][N], int sums[4][N], int column, int row)
{
    if (0 != check_num_vertical(fields, fields[row][column])
        || 0 != check_num_horisontal(fields, fields[row][column])){
        return -1;
    }
    if (column == 3){
        if(0 != check_left_to_righ(fields, sums, row)
			|| 0 != check_right_to_left(fields, sums, row))
        {
            return (-1);
        }
    }
	if (row == 3)
	{
		if ( 0 != check_top_to_bottom(fields, sums, column)
			|| 0 != check_bottom_to_top(fields, sums, column))
		{
            return (-1);
        }
	}
    return 0;
}
int backtrack(int fields[N][N], int sums[N][N], int column, int row)
{
	int success;
	int num;
	num = fields[row][column];
    if (column >= N){
        column = 0;
        row++;
    }
    if(0 != is_safe_rn(fields, sums, column, row))
        return -1;
    if (row == 3 && column == 3)
    {
        printf("Done!\n");
        return 0;
    }
    num = 1;
    column++;
    while (num <= N)
    {
        fields[row][column] = num;
        if(0 == backtrack(fields, sums, column, row))
            return 0;
        num++;
    }
    fields[row][column] = 0;
	return -1;
}
int main(int argc, char **argv)
{
    int arg_iter;
    int row;
    int column;
    int fields[N][N] = {0};
	int sums[N][N];

    if (argc != 2)
        return -1;
    row = 0;
    column = 0;
    while (arg_iter < N*4*2 - 1)
    {
        if (argv[1][arg_iter] == '\0')
        {
            return -1;
        }
        if (argv[1][N*8 - 1] != '\0')
        {
            return -1;
        }

        if (arg_iter % 2 == 0 && argv[1][arg_iter] >= 49 && argv[1][arg_iter] < 49+N){
           sums[row][column] = argv[1][arg_iter] - '0';
           column++;
           if (column == N){
                column = 0;
                row++;
           }
        }else if (arg_iter % 2 != 1 || argv[1][arg_iter] != ' ')
        {
            return -1;
        }
        arg_iter++;
    }


    print(sums);
    for(int i = 1; i<=4; i++){
        fields[0][0] = i;
        if (0 == backtrack(fields, sums, 0, 0)){
            print(fields);
            break;
        }
    }
}
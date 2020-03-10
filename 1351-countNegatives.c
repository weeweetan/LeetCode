#include <stdio.h>

//
// Created by 11135 on 2020/2/22.
//
int countNegatives(int** grid, int gridSize, int* gridColSize)
{
    int m = gridSize;
    int row = m - 1;
    int col = 0, ret = 0;
    int n = *gridColSize;

    while (row >= 0 && col < n)
    {
        if (grid[row][col] < 0)
        {
            ret += n - col;
            row--;
        }
        else
        {
            col++;
        }
    }

    return ret;
}

int main(int argc, char **argv)
{

    int temp[4][4] = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    int gridColSize = 4;
    int *grid[4];
    grid[0] = temp[0];
    grid[1] = temp[1];
    grid[2] = temp[2];
    grid[3] = temp[3];

    printf("%d\n", countNegatives(grid, 4, &gridColSize));
}
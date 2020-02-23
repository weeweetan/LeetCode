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

    int grid[4][4] = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    int gridColSize = 4;
    countNegatives(grid, 4, &gridColSize);
}
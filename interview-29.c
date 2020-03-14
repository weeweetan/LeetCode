//
// Created by 11135 on 2020/3/4.
//

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int *res = malloc(sizeof(int) * (*returnSize));
    if (matrix == NULL)
    {
        return NULL;
    }


    int l = 0, r = *matrixColSize - 1, t = 0, b = matrixSize - 1, x = 0;

    while (1)
    {
        for(int i = l; i <= r; i++) res[x++] = matrix[t][i]; // left to right.
        if(++t > b) break;
        for(int i = t; i <= b; i++) res[x++] = matrix[i][r]; // top to bottom.
        if(l > --r) break;
        for(int i = r; i >= l; i--) res[x++] = matrix[b][i]; // right to left.
        if(t > --b) break;
        for(int i = b; i >= t; i--) res[x++] = matrix[i][l]; // bottom to top.
        if(++l > r) break;
    }
    return res;

}

int main(int argc, char **argv)
{
    int *res;
    int *p[3];
    int matrix[3][3] = {1,2,3,4,5,6,7,8,9};
    int colsize = 3, ret_size = 9;
    p[0] = matrix[0];
    p[1] = matrix[1];
    p[2] = matrix[2];
    res = spiralOrder(p, 3, &colsize, &ret_size);
    for (int i = 0; i < 9; ++i) {
        printf("%d ", res[i]);
    }
}
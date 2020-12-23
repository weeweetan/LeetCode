//
// Created by 11135 on 2020/12/11.
//
#include <stdio.h>

int climbStairs(int n){
    int p = 0, q = 0, r = 1;
    for (int i = 1; i <= n; i++)
    {
        p = q;
        q = r;
        r = p + q;
    }
    return r;
}

int main(int argc, char **argv)
{
    printf("%d\n", climbStairs(2));
}

//
// Created by 11135 on 2020/1/12.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int subtractProductAndSum(int n)
{
    int sum = 0, product = 1, temp;
    while (n != 0)
    {
        temp = n % 10;
        sum += temp;
        product *= temp;
        n = n / 10;
    }

    return product - sum;
}


int main(int argc, char **argv)
{
    int a = 4421;
    printf("%d\n", subtractProductAndSum(a));
}
//
// Created by 11135 on 2020/5/31.
//
#include <stdio.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    int min = INT_MAX;
    int profit_price = 0, i = 0;
    
    for (i = 0; i < pricesSize; ++i) {
        if (prices[i] < min) {
            min = prices[i];
        } else if (prices[i] - min > profit_price) {
            profit_price = prices[i] - min;
        }
    }

    return profit_price;
    
}

int main(int argc, char **argv)
{
    int temp[] = {7,6,4,3,1};
    int size = sizeof(temp) / sizeof(int);

    printf("%d\n", maxProfit(temp, size));
}
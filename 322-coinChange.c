//
// Created by 11135 on 2020/3/8.
//

#include <stdio.h>
#include <limits.h>
#include <string.h>

int dp(int *coins, int coinsSize, int amount, int *count)
{
    if (amount < 0) return -1;
    if (amount == 0) return 0;
    if (count[amount - 1] != 0) return count[amount - 1];

    int min = INT_MAX;
    for (int i = 0; i < coinsSize; ++i) {
        int res = dp(coins, coinsSize, amount - coins[i], count);
        if (res >= 0 && res < min)
            min = 1 + res;
    }
    count[amount - 1] = (min == INT_MAX) ? -1 : min;
    return count[amount - 1];

}

int coinChange(int *coins, const int coinsSize, const int amount)
{
    int count[amount];
    memset(count, 0, sizeof(count));
    if (amount < 1) return 0;
    return dp(coins, coinsSize, amount, count);
}

int main(int argc, char **argv)
{
    int coins[] = {1,2};

    int ret = coinChange(coins, sizeof(coins)/sizeof(int), 11);
    printf("%d\n", ret);

}
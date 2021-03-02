//
// Created by 11135 on 2021/3/2.
//
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i < dp.size(); i++) {
            for (auto coin : coins)
            {
                if (i - coin < 0) continue;
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};

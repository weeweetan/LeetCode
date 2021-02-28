//
// Created by 11135 on 2021/2/28.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // dp数组全部初始化为0
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //base case
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        //反着遍历保证正确的状态转移
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};

//
// Created by 11135 on 2021/3/6.
//
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =  0;
        for (auto num : nums) sum += num;
        //和为奇数时， 不可能划分成两个和相等的集合
        if (sum % 2 != 0) return false;
        int n = nums.size();
        sum = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++) {
                if (j - nums[i - 1] < 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }
};

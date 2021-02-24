//
// Created by 11135 on 2021/2/1.
//
class Solution {
public:
    int numTrees(int n) {
        long long C = 1;
        for (int i = 0; i < n; i++)
        {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};

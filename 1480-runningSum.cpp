//
// Created by 11135 on 2020/9/21.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int tempSum = 0, temp = 0;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            temp = *it;
            *it = *it + tempSum;
            tempSum += temp;
        }

        return nums;
    }
};

int main(int argc, char **argv)
{
    vector<int> v1;
    for (int i = 1; i < 6; ++i) {
        v1.push_back(1);
    }
    Solution solution;
    vector<int> v2 = solution.runningSum(v1);
    for (auto it : v2)
    {
        cout << it << " ";
    }
    cout << endl;
}
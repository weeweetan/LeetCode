//
// Created by 11135 on 2020/9/25.
//

#include <iostream>
#include <vector>
using namespace std;
//使用vector的insert
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ans;
        for (int i = 0; i < index.size(); ++i) {
            ans.insert(ans.begin() + index[i], nums[i]);
        }
        return ans;
    }
};


int main(int argc, char **argv)
{
    vector<int> nums, index;

    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    index.push_back(0);
    index.push_back(1);
    index.push_back(2);
    index.push_back(2);
    index.push_back(1);

    Solution s;
    vector<int> temp = s.createTargetArray(nums, index);
    for (auto it : temp)
    {
        cout << it << " ";
    }
    cout << endl;
}

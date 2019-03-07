//
// Created by 11135 on 2019/2/25.
//
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};


int main(int argc, char *argv[])
{
    int temp[] = {0,1,2,2,3,0,4,2};
    vector<int> vec(temp, temp+8);
//    temp.push_back()
    Solution solution;
    int result = solution.removeElement(vec, 2);
    cout << result << endl;
}
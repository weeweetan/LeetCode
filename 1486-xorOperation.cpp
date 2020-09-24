//
// Created by 11135 on 2020/9/24.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            temp = temp ^ (start + 2 * i);
        }
        return temp;
    }
};


int main(int argc, char **argv)
{
    Solution s;
    cout << s.xorOperation(10, 5) << endl;
}
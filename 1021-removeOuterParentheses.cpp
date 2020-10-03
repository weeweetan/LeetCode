//
// Created by 11135 on 2020/9/23.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        int left = 1, right = 0;
        string res;
        //从第二个开始
        for (int i = 1; i < S.size(); ++i) {
            if (S[i] == '(') left++;
            else right++;

            if (left != right) res.push_back(S[i]);
            else {
                i++;
                left = 1;
                right = 0;
            }
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    string test = "(()())(())";
    Solution s;
    cout << s.removeOuterParentheses(test) << endl;
}

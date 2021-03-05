//
// Created by 11135 on 2021/3/3.
//
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> deads;
        for (auto s : deadends)
            deads.insert(s);
        set<string> visited;
        queue<string> q;

        int step = 0;
        q.push("0000");
        visited.insert("0000");

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();
                if (deads.count(cur))
                    continue;
                if (!cur.compare(target))
                    return step;

                for (int j = 0; j < 4; j++) {
                    for (int d = -1; d <= 1; d += 2) {
                        int y = ((cur.at(j) - '0') + d + 10) % 10;
                        string nei = cur.substr(0, j) + to_string(y) + cur.substr(j + 1);
                        if (!visited.count(nei)) {
                            visited.insert(nei);
                            q.push(nei);
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<string> deadends;
    deadends.push_back("0201");
    deadends.push_back("0101");
    deadends.push_back("0102");
    deadends.push_back("1212");
    deadends.push_back("2002");
    string target = "0202";
    cout << s.openLock(deadends, target);
}
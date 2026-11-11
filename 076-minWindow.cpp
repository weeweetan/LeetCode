//
// Created by 11135 on 2021/2/23.
//
#include <string>
#include <unordered_map>
#include <cstddef>

using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || t.size() > s.size()) return "";

        unordered_map<char, size_t> need, window;
        for (char c : t) need[c]++;

        size_t left = 0, right = 0;
        size_t valid = 0;

        size_t start = 0, len = string::npos;
        while (right < s.size())
        {
            char c = s[right];
            right++;
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            while (valid == need.size())
            {
                if (right - left < len)
                {
                    start = left;
                    len = right - left;
                }

                char d = s[left];
                left++;
                if (need.count(d))
                {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return len == string::npos ? "" : s.substr(start, len);
    }
};

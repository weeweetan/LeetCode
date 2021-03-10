//
// Created by 11135 on 2021/3/8.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    static bool compare(vector<int> a, vector<int> b)
    {
        return (a[1] < b[1]);
    }

    int intervalSchedule(vector<vector<int>>& intervals)
    {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int count = 1;
        int x_end = intervals[0][1];
        for (auto interval : intervals) {
            int start = interval[0];
            if (start >= x_end)
            {
                count++;
                x_end = interval[1];
            }
        }

        return count;
    }


    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        return n - intervalSchedule(intervals);
    }
};


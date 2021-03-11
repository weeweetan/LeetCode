//
// Created by 11135 on 2021/3/10.
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
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), compare);
        int count = 1;
        int x_end = points[0][1];
        for (auto point : points) {
            int start = point[0];
            if (start > x_end)
            {
                count++;
                x_end = point[1];
            }
        }

        return count;
    }
};

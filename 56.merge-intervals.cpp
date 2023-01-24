/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        set<vector<int>> mySet(intervals.begin(), intervals.end());
        vector<vector<int>> results(mySet.begin(), mySet.end());
        for (int i = 1; i < results.size();)
        {
            int pre_start = results[i - 1][0], pre_end = results[i - 1][1];
            int &start = results[i][0], &end = results[i][1];
            if (pre_end >= start)
            {
                start = min(pre_start, start);
                end = max(pre_end, end);
                results.erase(results.begin() + i - 1);
            }
            else
                i++;
        }
        return results;
    }
};
// @lc code=end

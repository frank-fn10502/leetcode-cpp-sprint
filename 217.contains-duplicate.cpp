/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    //可以使用 set, hashset
    map<int, char> mapFind;
    bool containsDuplicate(vector<int> &nums)
    {
        for (auto n : nums)
            if (mapFind.find(n) != mapFind.end())
                return true;
            else
                mapFind[n] = 1;
        return false;
    }
};
// @lc code=end

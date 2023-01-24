/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        if (nums[0] == 0)
            return false;

        int last = nums.size() - 1, reach_idex = 0;
        for (int i = 0; i <= reach_idex; i++)
        {
            reach_idex = max(reach_idex, i + nums[i]);
            if (reach_idex >= last)
                return true;
        }

        return false;
    }
};
// @lc code=end

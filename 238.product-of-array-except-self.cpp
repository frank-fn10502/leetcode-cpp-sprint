/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        //vector 可以初始化一個全部為 0 的 vector
        vector<int> result;
        int sum = 1;
        int hasZero = 0;
        for (auto n : nums)
        {
            if (n != 0)
                sum *= n;
            else
                hasZero++;
        }
        for (auto n : nums)
        {
            if (hasZero)
                if (n == 0)
                    result.push_back(hasZero == 1 ? sum : 0);
                else
                    result.push_back(0);
            else
                result.push_back(sum / n);
        }
        return result;
    }
};
// @lc code=end

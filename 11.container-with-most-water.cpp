/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int ln = 0, rn = 0, result = 0;
        while (left < right)
        {
            ln = height[left];
            rn = height[right];

            int h = min(ln, rn);
            int w = right - left;
            int area = h * w;
            result = max(result, area);

            if (ln < rn)
                left++;
            else if (rn < ln)
                right--;
            else
            {
                left++;
                right--;
            }
        }
        return result;
    }
};
// @lc code=end

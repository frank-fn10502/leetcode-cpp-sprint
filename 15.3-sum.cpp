/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums[0] > 0)
            return {};

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            int sum = 0;
            int last_left = -1, last_right = -1;
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                if (sum < 0)
                    left++;
                else if (sum > 0)
                    right--;
                else
                {
                    // 這邊排序過後, 相同的都會集中在一起, 可以用 while 分別跳過 left & right 重複的數字
                    if (last_left != -1 &&
                        (nums[left] == nums[last_left] && nums[right] == nums[last_right]))
                    {
                        left++;
                        right--;
                        continue;
                    }
                    result.push_back({nums[i], nums[left], nums[right]});
                    last_left = left;
                    last_right = right;
                }
            }
        }
        return result;
    }
};
// @lc code=end

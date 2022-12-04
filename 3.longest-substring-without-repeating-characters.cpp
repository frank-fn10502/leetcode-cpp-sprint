/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int result = 0;
        map<char, char> exists;
        int l = 0, r = 0;
        for (int r = 0; r < s.length() && l < s.length();)
        {
            auto c = s[r];
            if (exists.find(c) != exists.end())
            {
                exists.erase(s[l]); //移除最左邊
                l++;
            }
            else
            {
                exists[c] = 1;
                result = max(result, r - l + 1);
                r++;
            }
        }
        return max(result, (int)exists.size());
    }
};
// @lc code=end

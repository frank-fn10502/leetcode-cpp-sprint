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
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                auto c = s[j];
                if (exists.find(c) != exists.end())
                {
                    result = max(result, (int)exists.size());
                    exists.clear();
                    break;
                }
                exists[c] = 1;
            }
        }
        return max(result, (int)exists.size());
    }
};
// @lc code=end

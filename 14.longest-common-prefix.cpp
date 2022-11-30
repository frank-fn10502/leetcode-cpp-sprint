/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int max_length = 200;
        string result = "";

        char t = ' ';
        for (int i = 0; i < max_length; i++)
        {
            t = strs[0][i];
            for (auto str : strs)
            {
                if (i >= str.length() or str[i] != t)
                {
                    return result;
                }
            }
            result += t;
        }

        return result;
    }
};
// @lc code=end

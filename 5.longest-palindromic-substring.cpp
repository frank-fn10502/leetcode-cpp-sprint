/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n == 1)
            return s.substr(0, 1);

        string result = s.substr(0, 1);
        bool table[n][n];
        memset(table, 0, sizeof(table));

        for (int i = 0; i < n; i++)
            table[i][i] = 1;

        for (int end = 1; end < n; end++)
        {
            for (int start = 0; start < end; start++)
            {
                if (s[start] == s[end])
                {
                    if ((end - start == 1 || table[start + 1][end - 1] == true))
                    {
                        table[start][end] = true;
                        if (end - start + 1 > result.length())
                            result = s.substr(start, end - start + 1);
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

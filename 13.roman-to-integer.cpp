/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> datas = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int result = 0;
        for (int i = 0, j = 1; i < s.length();)
        {
            if ((s[i] == 'I' && (s[j] == 'V' || s[j] == 'X')) ||
                (s[i] == 'X' && (s[j] == 'L' || s[j] == 'C')) ||
                (s[i] == 'C' && (s[j] == 'D' || s[j] == 'M')))
            {
                result += datas[s[j]] - datas[s[i]];
                i += 2;
                j += 2;
            }
            else
            {
                result += datas[s[i]];
                i++;
                j++;
            }
        }
        return result;
    }
};
// @lc code=end

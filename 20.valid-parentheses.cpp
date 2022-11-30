/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        map<char, char> dict = {
            {'}', '{'},
            {']', '['},
            {')', '('},
        };
        for (auto c : s)
        {
            if (c == '(' or c == '[' or c == '{')
            {
                stack.push(c);
            }
            else
            {
                if (stack.empty())
                    return false;
                if (stack.top() != dict[c])
                    return false;
                stack.pop();
            }
        }
        return stack.empty();
    }
};
// @lc code=end

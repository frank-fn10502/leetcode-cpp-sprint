/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        int div = 10, div_result = x, remain = 0;
        long temp = 0;

        while (div_result)
        {
            remain = div_result % div;
            temp = temp * 10 + remain;
            div_result /= div;
        }
        return temp == x;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int in = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < in)
                in = prices[i];
            else
                profit = max(prices[i] - in, profit);
        }
        return profit;
    }
};
// @lc code=end

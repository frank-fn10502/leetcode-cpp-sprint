/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int last = matrix.size();
        for (int i = 0; i < last; i++)
            for (int j = i + 1; j < last; j++)
                swap(matrix[i][j], matrix[j][i]);
        for (auto &m : matrix)
            reverse(m.begin(), m.end());
    }
};
// @lc code=end

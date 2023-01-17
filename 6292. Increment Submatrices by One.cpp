#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (auto query : queries)
        {
            int r1 = query[0], r2 = query[2];
            int c1 = query[1], c2 = query[3];
            for (int i = r1; i <= r2; i++)
            {
                mat[i][c1]++;
                if (c2 + 1 < n)
                    mat[i][c2 + 1]--;
            }
        }
        int acc = 0;
        for (auto &row : mat)
        {
            acc = 0;
            for (auto &col : row)
            {
                acc += col;
                col = acc;
            }
        }
        return mat;
    }
};

int main()
{
    vector<vector<int>> queries{{1, 1, 2, 2}, {0, 0, 1, 1}};
    auto sol = new Solution();
    sol->rangeAddQueries(3, queries);
}
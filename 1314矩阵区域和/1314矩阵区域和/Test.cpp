#include<iostream>
#include<vector>
using namespace std;

//给你一个 m x n 的矩阵 mat 和一个整数 k ，请你返回一个矩阵 answer ，其中每个 answer[i][j] 是所有满足下述条件的元素 mat[r][c] 的和：
//
//i - k <= r <= i + k,
//j - k <= c <= j + k 且
//(r, c) 在矩阵内。
//
//
//示例 1：
//
//输入：mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], k = 1
//输出： [[12, 21, 16], [27, 45, 33], [24, 39, 28]]
//示例 2：
//
//输入：mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], k = 2
//输出： [[45, 45, 45], [45, 45, 45], [45, 45, 45]]

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + mat[i - 1][j - 1] - dp[i - 1][j - 1];

        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int x1 = max(i - k, 0) + 1, y1 = max(j - k, 0) + 1;
                int x2 = min(i + k, m - 1) + 1, y2 = min(j + k, n - 1) + 1;

                ret[i][j] = dp[x2][y2] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] - dp[x2][y1 - 1];
            }

        return ret;
    }
};

int main()
{

    return 0;
}
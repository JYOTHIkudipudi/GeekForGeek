/*  Cut Matrix

Given a matrix of 0s and 1s and an integer k, divide the matrix into k pieces such that each piece has at least one 1 in it.
A cut can be made in the following way:

Choose a direction: vertical or horizontal.
Choose an index to cut the matrix into two pieces.
If the cut is horizontal, only the bottom part can be cut further.
If the cut is vertical, only the right part can be cut further.
Return the number of different ways to divide the matrix modulo 1e9 + 7.

Examples:

Input: matrix = [[1, 0, 0], [1, 1, 1], [0, 0,0]], k = 3 
Output: 3
Explanation: There are 3 valid ways to divide the matrix into 3 pieces each having at least one 1 - horizontal cut after row 0 then vertical cut after col 0 on bottom, horizontal cut after row 0 then vertical cut after col 1 on bottom, and vertical cut after col 0 then vertical cut after col 1 on the right part.
 
Input: matrix = [[0, 0], [1, 1]], k = 2
Output: 1
Explanation: Only way is to cut vertically in the middle since the top half has no 1.
Input: matrix = [[1, 0], [0, 0]], k = 1
Output: 1
Explanation: No cut needed as k = 1, the whole matrix is one piece with at least one 1.
Constraints:
1 <= n, m, k <= 200  */


class Solution {
public:
    static const int MOD = 1000000007;
    static const int MX = 202;

    int findWays(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        static int suf[MX][MX];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) suf[i][j] = 0;
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
                suf[i][j] = matrix[i][j] + suf[i+1][j] + suf[i][j+1] - suf[i+1][j+1];

        static int nextRow[MX][MX], nextCol[MX][MX];
        for (int j = 0; j < m; j++) {
            nextRow[n][j] = n;
            for (int i = n - 1; i >= 0; i--) {
                bool rowHasOne = (suf[i][j] - suf[i+1][j]) > 0;
                nextRow[i][j] = rowHasOne ? i : nextRow[i+1][j];
            }
        }
        for (int i = 0; i < n; i++) {
            nextCol[i][m] = m;
            for (int j = m - 1; j >= 0; j--) {
                bool colHasOne = (suf[i][j] - suf[i][j+1]) > 0;
                nextCol[i][j] = colHasOne ? j : nextCol[i][j+1];
            }
        }

        static int dp[2][MX][MX];
        int cur = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dp[cur][i][j] = (suf[i][j] > 0) ? 1 : 0;

        if (k == 1) return dp[cur][0][0];

        static int colSuf[MX][MX], rowSuf[MX][MX];

        for (int cut = 1; cut < k; cut++) {
            int prev = cur, nxt = cur ^ 1;

            for (int j = 0; j < m; j++) {
                colSuf[n][j] = 0;
                for (int i = n - 1; i >= 0; i--) {
                    int v = colSuf[i+1][j] + dp[prev][i][j];
                    colSuf[i][j] = v >= MOD ? v - MOD : v;
                }
            }
            for (int i = 0; i < n; i++) {
                rowSuf[i][m] = 0;
                for (int j = m - 1; j >= 0; j--) {
                    int v = rowSuf[i][j+1] + dp[prev][i][j];
                    rowSuf[i][j] = v >= MOD ? v - MOD : v;
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int ways = 0;
                    int z = nextRow[i][j];
                    if (z < n) {
                        int r0 = z + 1;
                        if (r0 < n) ways += colSuf[r0][j];
                    }
                    int c = nextCol[i][j];
                    if (c < m) {
                        int c0 = c + 1;
                        if (c0 < m) ways += rowSuf[i][c0];
                    }
                    dp[nxt][i][j] = ways >= MOD ? ways - MOD : ways;
                }
            }
            cur = nxt;
        }

        return dp[cur][0][0];
    }
};

/*  Minimum Squares with Full Cuts
Given a rectangular paper with dimensions n × m, find the minimum number of squares that can be formed by cutting the paper.
Each cut must be made completely across the remaining paper, either horizontally or vertically.

Examples:

Input: n = 4, m = 5
Output: 5
Explanation: One square of size 4 x 4 and four squares of size 1 x 1 are required.
Input: n = 2, m = 4
Output:  2
Explanation: Two squares of size 2 x 2 are enough to fill the rectangle.
Input: n = 11, m = 13
Output: 8
Explanation: One square of size 11 x 11, five squares of size 2 x 2, and two squares of size 1 x 1 are formed by following the rule. 
Please note that if we are allowed to make partial horizontal or vertical cuts, we can have 6 squares which is a different interesting problem, Min Cut Square.

Constraints:
1 ≤ n, m ≤ 109  */

class Solution {
  public:
    int minSquares(int n, int m) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= m && j * j <= i; j++) {
                if (dp[i - j * j] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
                }
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};

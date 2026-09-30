/*  Ways to Reach Origin

Difficulty: **Medium**Accuracy: **53.93%**Submissions: **61K+**Points: **4**Average Time: **15m**

Geek is standing at a point **(x, y)** on a 2D grid and wants to reach the origin (0, 0).

From any point, Geek can move in only two directions: left, from (x, y) to (x - 1, y), or down, from (x, y) to (x, y - 1).

Find the total number of distinct paths for Geek to reach (0, 0) from (x, y). Since the answer can be very large, return it modulo 109+7.

**Examples:**

```
Input: x = 3, y = 0
Output: 1
Explanation: The only possible path is (3, 0) -> (2, 0) -> (1, 0) -> (0, 0), since y = 0, there is no option to move down at any step.
```

```
Input: x = 3, y = 6
Output: 84
Explanation: There are a total of 84 distinct paths from (3, 6) to (0, 0) using only left and down moves.
```

**Constraints:**

0 ≤ x, y ≤ 500

*/
class Solution {
public:
    int ways(int x, int y) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

        // Base cases
        for (int i = 0; i <= x; i++)
            dp[i][0] = 1;

        for (int j = 0; j <= y; j++)
            dp[0][j] = 1;

        // DP
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }

        return dp[x][y];
    }
};

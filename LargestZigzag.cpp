/*  Largest Zigzag Sequence


Given a square matrix mat[][] of size n × n. A zigzag sequence starts from the top and ends at the bottom. Two consecutive elements of sequence cannot belong to the same column.

Return the maximum sum of such a zigzag sequence.

Examples:

Input: mat[][] = [[3, 1, 2], [4, 8, 5], [6, 9, 7]]
Output: 18
Explanation:

One optimal zigzag sequence is: 3 -> 8 -> 7, where the sum = 3 + 8 + 7 = 18.
Input: mat[][] = [[1, 2, 4], [3, 9, 6], [11, 3, 15]]
Output: 28
Explanation:

One optimal zigzag sequence is: 4 -> 9 -> 15, where the sum = 4 + 9 + 15 = 28.
Constraints:
1 ≤ n ≤ 100
1 ≤ mat[i][j] ≤ 1000   */

class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<int> dp(n);

        // First row
        for (int j = 0; j < n; j++) {
            dp[j] = mat[0][j];
        }

        // Process remaining rows
        for (int i = 1; i < n; i++) {
            vector<int> next(n, 0);

            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    // Previous column must be different
                    if (k != j) {
                        next[j] = max(next[j],
                                      dp[k] + mat[i][j]);
                    }
                }
            }

            dp = next;
        }

        return *max_element(dp.begin(), dp.end());
    }
};

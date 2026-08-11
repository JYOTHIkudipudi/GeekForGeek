/*  Largest Odd Squares with Limited 1s


Given a binary matrix mat[][] of size n*m and an integer k, process a list of queries queries[][]. Each query contains coordinates [i, j] of the center of a square.

For every query, find the side length of the largest odd-sized square centered at cell (i, j) such that the square contains at most k ones.
 A square centered at (i, j) expands outward symmetrically in all four directions by the same number of cells, so its side length is always odd.
Note: If no odd-sized square centered at the given cell satisfies the condition of containing at most k ones, return -1 for that query.

Examples:

Input: mat[][] = [[1, 0, 1, 0, 0], [1, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 0, 0, 1, 0]], queries[][] = [[1, 2]], k = 9
Output: [3]
Explanation: The largest odd-sized square centered at (1, 2) is the 3 × 3 square spanning rows 0 to 2 and columns 1 to 3. 
It contains 6 ones, which is at most k = 9. Hence, the answer is 3.
Input: mat[][] = [[1, 1, 1], [1, 1, 1], [1, 1, 1]], queries[][] = [[1, 1], [2, 2]], K = 9
Output: [3, 1]
Explanation: For query (1, 1), the largest valid square is the entire 3 × 3 matrix, which contains 9 ones. Hence, the answer is 3.
For query (2, 2), no expansion is possible without going outside the matrix, so only the 1 × 1 square centered at (2, 2) is valid. Hence, the answer is 1.
Constraints:
1 ≤ mat.size(), mat[0].size() ≤ 500
1 ≤ queries.size() ≤ 104
0 ≤ queries[q][0] < mat.size()
0 ≤ queries[q][1] < mat[0].size()
0 ≤ k ≤ mat.size() * mat[0].size()   */

class Solution {
public:
    vector<int> largestSquare(vector<vector<int>>& mat,
                               vector<vector<int>>& queries,
                               int k) {
        
        int n = mat.size();
        int m = mat[0].size();

        // 2D Prefix Sum
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i + 1][j + 1] =
                    mat[i][j]
                    + pref[i][j + 1]
                    + pref[i + 1][j]
                    - pref[i][j];
            }
        }

        // Function to get number of 1s in rectangle
        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return pref[r2 + 1][c2 + 1]
                 - pref[r1][c2 + 1]
                 - pref[r2 + 1][c1]
                 + pref[r1][c1];
        };

        vector<int> ans;

        for (auto &q : queries) {
            int i = q[0];
            int j = q[1];

            // Maximum possible radius
            int maxRadius = min({i, n - 1 - i, j, m - 1 - j});

            // If even 1x1 has more than k ones
            if (mat[i][j] > k) {
                ans.push_back(-1);
                continue;
            }

            int low = 0;
            int high = maxRadius;
            int best = 0;

            while (low <= high) {
                int radius = low + (high - low) / 2;

                int r1 = i - radius;
                int c1 = j - radius;
                int r2 = i + radius;
                int c2 = j + radius;

                int ones = getSum(r1, c1, r2, c2);

                if (ones <= k) {
                    best = radius;
                    low = radius + 1;
                } else {
                    high = radius - 1;
                }
            }

            // radius r gives side length 2*r + 1
            ans.push_back(2 * best + 1);
        }

        return ans;
    }
};

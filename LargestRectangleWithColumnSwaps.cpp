/* Largest Rectangle with Column Swaps

Given a binary matrix mat[][] of size n × m containing only 0s and 1s, any pair of columns may be swapped any number of times.
Return the maximum area of a rectangle consisting entirely of 1's that can be formed after performing the column swaps.

Examples:

Input: mat[][] = [[0, 1, 0, 1, 0], [0, 1, 0, 1, 1], [1, 1, 0, 1, 0]]
Output: 6
Explanation: After swapping the 2nd and 3rd columns, the largest rectangle of 1s has an area of 6.
 
Input: mat[][] = [[0, 1, 1, 0, 0], [1, 1, 1, 0, 1], [1, 1, 1, 0, 1], [1, 1, 1, 1, 1]]
Output: 12
Explanation: After swapping the 4th and 5th columns, the largest rectangle of 1s has an area of 12.

Constraints:

1 ≤ n, m ≤ 103
0 ≤ mat[i][j] ≤ 1
mat.rows = n
mat.cols = m
  */

class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Step 1: Convert matrix into histogram heights
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    mat[i][j] += mat[i - 1][j];
                }
            }
        }

        int ans = 0;

        // Step 2: For every row
        for (int i = 0; i < n; i++) {

            // Column swaps are allowed,
            // so sort heights in descending order
            sort(mat[i].begin(), mat[i].end(), greater<int>());

            // Step 3: Calculate area
            for (int j = 0; j < m; j++) {
                int height = mat[i][j];
                int width = j + 1;

                ans = max(ans, height * width);
            }
        }

        return ans;
    }
};

/*  Largest Unblocked Submatrix

Given two integers n and m, and an array arr[][] of size k, where arr[i] = [r, c] represents a blocked cell (1-based indexing) in an n × m grid. 
Each blocked cell blocks its entire row and column. Find the largest continuous unblocked area in the grid.

Note: No two blocked cells are in the same row or the same column.

Examples:

Input: n = 5, m = 5, arr[][] = [[2, 3], [5, 1]]
Output: 4
Explanation:

- Blocked cells (2, 3) and (5, 1) block rows 2, 5 and columns 1, 3.
- The longest unblocked row segment has length 2 (rows 3–4).
- The longest unblocked column segment has length 2 (columns 4–5).
- Therefore, the largest unblocked rectangle has area 2 × 2 = 4.
Input: n = 2, m = 2, arr[][] = [[2, 2]]

Output: 1
Explanation: Since only (1,1) cell is free from the enemy hence answer is 1.
Constraints:
1 ≤ n, m ≤ 104
0 ≤ k ≤ min(n, m)
1 ≤ r ≤ n
1 ≤ c ≤ m   */

class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        vector<int> rows, cols;
        
        for (auto &x : arr) {
            rows.push_back(x[0]);
            cols.push_back(x[1]);
        }
        
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        
        int maxRows = 0, maxCols = 0;
        
        // Maximum consecutive unblocked rows
        int prev = 0;
        for (int r : rows) {
            maxRows = max(maxRows, r - prev - 1);
            prev = r;
        }
        maxRows = max(maxRows, n - prev);
        
        // Maximum consecutive unblocked columns
        prev = 0;
        for (int c : cols) {
            maxCols = max(maxCols, c - prev - 1);
            prev = c;
        }
        maxCols = max(maxCols, m - prev);
        
        return maxRows * maxCols;
    }
};

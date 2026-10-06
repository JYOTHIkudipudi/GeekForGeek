/*  Longest Increasing Path in Matrix

Given a matrix with n rows and m columns, find the length of the longest path such that:

The path can start and end at any cell.

A cell cannot be visited more than once.

The values in path are strictly increasing. 

From each cell,  you can move left, right, up, or down.

Diagonal moves and moves outside the matrix are not allowed.



Examples:

Input: n = 3, m = 3, matrix[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: 5
Explanation: One such path is 1 -> 2 -> 3 -> 6 -> 9, where each number is strictly greater than the previous.
image

Input: n = 3, m = 3, matrix[][] = [[3, 4, 5], [6, 2, 6], [2, 2, 1]]
Output: 4
Explanation: One of the longest increasing paths is 3 -> 4 -> 5 -> 6.
image

Input: n = 2, m = 2, matrix[][] = [[1, 1], [1, 1]]
Output: 1
Explanation: There can at most one vertex as all vertices are same.

Constraints:

1 ≤ n, m ≤ 1000
0 ≤ matrix[i][j] ≤ 230   */

class Solution {
  public:
    
    int dfs(int i, int j, vector<vector<int>>& matrix,
            vector<vector<int>>& dp, int n, int m) {
        
        // Already calculated
        if (dp[i][j] != 0)
            return dp[i][j];
        
        dp[i][j] = 1;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            // Inside matrix + strictly increasing
            if (ni >= 0 && ni < n &&
                nj >= 0 && nj < m &&
                matrix[ni][nj] > matrix[i][j]) {
                
                dp[i][j] = max(dp[i][j],
                                1 + dfs(ni, nj, matrix, dp, n, m));
            }
        }
        
        return dp[i][j];
    }
    
    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        int ans = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix, dp, n, m));
            }
        }
        
        return ans;
    }
};

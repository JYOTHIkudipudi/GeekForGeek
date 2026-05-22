/*   1s Surrounded by 0s

Given an n × m binary matrix grid[][], find the total count of all cells containing 1 that are unable to move out of the grid through a path of adjacent 1s.

Adjacency means you can only move in four directions: Up, Down, Left, and Right. Diagonal moves are not allowed.
Assume that the space immediately outside the grid is an open path. Any 1 located directly on the outer boundary of the 
grid (first row, last row, first column, or last column) can immediately step out, and any 1 connected to it can follow and also step out of the grid.
Examples:

Input: grid[][] = [[0, 0, 0, 0],
		[1, 0, 1, 0],
		[0, 1, 1, 0],
		[0, 0, 0, 0]]
Output: 3
Explanation: The highlighted cells represent the land cells.
 
Input: grid[][] = [[1, 1, 0, 0, 0, 1]
		[0, 1, 1, 0, 1, 0],
		[0, 0, 0, 1, 1, 0],
		[0, 0, 0, 1, 1, 0],
		[0, 1, 0, 1, 0, 0],
		[1, 1, 0, 0, 0, 1]]
Output: 6
Explanation: The highlighted cells represent the land cells.
425537429
Constraints:
1 ≤ n, m ≤ 500
0 ≤ grid[i][j] ≤ 1   */

class Solution {
  public:
    
    void dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int n, int m) {
        
        vis[i][j] = 1;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            if (ni >= 0 && nj >= 0 &&
                ni < n && nj < m &&
                grid[ni][nj] == 1 &&
                !vis[ni][nj]) {
                    
                dfs(ni, nj, grid, vis, n, m);
            }
        }
    }
    
    int cntOnes(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // First and last column
        for (int i = 0; i < n; i++) {
            
            if (grid[i][0] == 1 && !vis[i][0])
                dfs(i, 0, grid, vis, n, m);
                
            if (grid[i][m - 1] == 1 && !vis[i][m - 1])
                dfs(i, m - 1, grid, vis, n, m);
        }
        
        // First and last row
        for (int j = 0; j < m; j++) {
            
            if (grid[0][j] == 1 && !vis[0][j])
                dfs(0, j, grid, vis, n, m);
                
            if (grid[n - 1][j] == 1 && !vis[n - 1][j])
                dfs(n - 1, j, grid, vis, n, m);
        }
        
        int cnt = 0;
        
        // Count enclosed 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (grid[i][j] == 1 && !vis[i][j])
                    cnt++;
            }
        }
        
        return cnt;
    }
};

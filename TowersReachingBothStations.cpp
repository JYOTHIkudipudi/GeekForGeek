/*  Towers Reaching Both Stations

Given a matrix mat[][] of size n x m, where mat[i][j] represents the signal strength of a communication tower. Two control stations monitor the network:

Station P covers the top and left boundaries of the grid.
Station Q covers the bottom and right boundaries of the grid.
A signal can propagate from a tower to one of its neighbouring towers in the four directions (North, South, East, and West) only if the neighbouring tower has a signal strength less than or equal to that of the current tower.

Determine the number of towers (x, y) from which a signal can eventually reach both Station P and Station Q. Any tower located on a boundary covered by a station can transmit directly to that station.

Examples:

Input: mat[][] = [[1, 2, 2, 3, 5], [3, 2, 3, 4, 4], [2, 4, 5, 3, 1], [6, 7, 1, 4, 5], [5, 1, 1, 2, 4]]
Output: 7
Explanation: 

(0, 4) & (4, 0) are part of both P & Q 
(1, 3) reaches P using (1,3)->(0,3) and Q using (1,3)->(1,4)
(1, 4) reaches P using (1,4)->(1,3)->(1,2)->(0,2) and it is on Q
(2, 2) reaches P using (2,2)->(2,1)->(2,0) and Q using (2,2)->(2,3)->(2,4)
(3, 0) is on P and reaches Q using (3,0)->(4,0)
(3, 1) reaches P using (3,1)->(3,0) and Q using (3,1)->(4,1)
Input: mat[][] = [[2, 2], [2, 2]]
Output: 4
Explanation: In the following example, all cells allow signals to propagate to both the stations.
Constraints:
1 ≤ n, m ≤ 103
1 ≤ mat[i][j] ≤ 103  */

class Solution {
  public:
    int n, m;
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    void dfs(int i, int j, vector<vector<int>> &mat,
             vector<vector<bool>> &vis) {
        
        vis[i][j] = true;
        
        for(auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];
            
            if(ni >= 0 && ni < n &&
               nj >= 0 && nj < m &&
               !vis[ni][nj] &&
               mat[ni][nj] >= mat[i][j]) {
                   
                dfs(ni, nj, mat, vis);
            }
        }
    }
    
    int countCoordinates(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        
        vector<vector<bool>> P(n, vector<bool>(m, false));
        vector<vector<bool>> Q(n, vector<bool>(m, false));
        
        // Station P (Top row)
        for(int j = 0; j < m; j++) {
            if(!P[0][j])
                dfs(0, j, mat, P);
        }
        
        // Station P (Left column)
        for(int i = 0; i < n; i++) {
            if(!P[i][0])
                dfs(i, 0, mat, P);
        }
        
        // Station Q (Bottom row)
        for(int j = 0; j < m; j++) {
            if(!Q[n-1][j])
                dfs(n-1, j, mat, Q);
        }
        
        // Station Q (Right column)
        for(int i = 0; i < n; i++) {
            if(!Q[i][m-1])
                dfs(i, m-1, mat, Q);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(P[i][j] && Q[i][j])
                    ans++;
            }
        }
        
        return ans;
    }
};

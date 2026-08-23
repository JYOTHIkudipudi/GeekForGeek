/* Geek in a Maze
Given a maze mat[][] of size n × m, where each cell is either:

'.' representing an empty cell, or
'#' representing an obstacle.
Find the number of distinct empty cells that Geek can visit starting from the cell (r, c).

Geek can move up, down, left, or right to an adjacent non-obstacle cell inside the maze.
On any path, Geek can make at most u upward moves and d downward moves.
There is no limit on the number of left or right moves.
If the starting cell is an obstacle, return 0.
Note :  There can be multiple paths starting from [r, c].

Examples:

Input: r = 1, c = 0, u = 1, d = 1, mat = [['.', '.', '.'], ['.', '#', '.'], ['#', '.', '.']]
Output: 5
Explanation: Geek starts from (1, 0) and follows the path (1,0)->(0,0)->(0,1)->(0,2)->(1,2). The cells (1,1) and (2,0) are obstacles, so they cannot be visited. Hence, Geek can visit 5 distinct empty cells.
 
Input: r = 2, c = 1, u = 2, d = 2, mat = [['.', '.', '.'], ['.', '#', '.'], ['.', '.', '.']]
Output: 8
Explanation: Geek starts from (2, 1) and follows the path (2,1)->(2,2)->(1,2)->(0,2)->(0,1)->(0,0)->(1,0)->(2,0). The cell (1,1) is an obstacle, so it cannot be visited. Hence, Geek can visit all 8 empty cells.

Input: r = 2, c = 1, u = 1, d = 0, mat = [['.', '.', '.'], ['.', '#', '.'], ['.', '.', '.']]
Output: 5
Explanation: The paths followed are (2, 1)->(2, 0)->(1, 0) and (2, 1)->(2, 2)->(1, 2)
Constraints:

1 ≤ n, m ≤ 106
0 ≤ r, c < 106
0 ≤ u, d ≤ 106
   */

class Solution {
  public:
    int numberOfCells(int r, int c, int u, int d,
                      vector<vector<char>> &mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        // Starting cell is an obstacle
        if (mat[r][c] == '#')
            return 0;
        
        const int INF = 1e9;
        
        // dist[i][j] = minimum upward moves needed
        vector<vector<int>> dist(n, vector<int>(m, INF));
        
        deque<pair<int, int>> dq;
        
        dist[r][c] = 0;
        dq.push_front({r, c});
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dr[k];
                int ny = y + dc[k];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                
                if (mat[nx][ny] == '#')
                    continue;
                
                // Moving up costs 1, everything else costs 0
                int cost = (dr[k] == -1) ? 1 : 0;
                
                if (dist[x][y] + cost < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost;
                    
                    if (cost == 1)
                        dq.push_back({nx, ny});
                    else
                        dq.push_front({nx, ny});
                }
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (dist[i][j] == INF)
                    continue;
                
                int upUsed = dist[i][j];
                
                // down - up = currentRow - startingRow
                int downUsed = upUsed + (i - r);
                
                if (upUsed <= u && downUsed <= d)
                    ans++;
            }
        }
        
        return ans;
    }
};

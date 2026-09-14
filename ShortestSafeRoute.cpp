/*  Shortest Safe Route in Grid
Given a 2D matrix mat[][] of size n × m, where each cell is either 0 (landmine) or 1 (safe),
find the minimum number of steps required to travel from any cell in the leftmost column to any cell in the rightmost column.

You can move only in four directions: up, down, left, and right.
A cell is unsafe if it contains a landmine or is directly adjacent (up, down, left, or right) to a landmine, and such cells must be avoided.
Return -1 if no safe path exists.
Examples:

Input: mat[][] = [[1, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 0, 1], [1, 1, 1, 1, 0]]

Output: 6
Explanation: We can see that length of shortest safe route is 6. 

Input: mat[][] = [[1, 1, 1, 1, 1], [1, 1, 0, 1, 1], [1, 1, 1, 1, 1]]

Output: -1
Explanation: There is no possible path from first column to last column.
Constraints:

1 ≤ n, m ≤ 103
0 ≤ mat[i][j] ≤ 1
  */

class Solution {
public:
    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        // safe[i][j] = true if we can stand on this cell
        vector<vector<int>> safe(n, vector<int>(m, 1));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Mark landmines and their adjacent cells as unsafe
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    safe[i][j] = 0;

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            safe[ni][nj] = 0;
                        }
                    }
                }
            }
        }

        // BFS
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        // We can start from any safe cell in the first column
        for (int i = 0; i < n; i++) {
            if (safe[i][0]) {
                q.push({i, 0});
                dist[i][0] = 1;
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Reached the last column
            if (y == m - 1)
                return dist[x][y];

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n &&
                    ny >= 0 && ny < m &&
                    safe[nx][ny] &&
                    dist[nx][ny] == -1) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};

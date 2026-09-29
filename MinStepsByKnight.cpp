/*   Min Steps by Knight
Given a square chessboard of size n × n, the initial position knightPos and target position targetPos of a Knight are given. 
Find the minimum number of moves required for the Knight to reach targetPos.

A Knight moves in an L-shape, covering 2 cells in one direction and 1 cell perpendicular to it. From (x, y), it can move to: (x ± 2, y ± 1) and (x ± 1, y ± 2)

This gives at most 8 possible moves:


Note: The positions are given using 1-based indexing.

Examples:

Input: n = 3, knightPos[] = [3, 3], targetPos[]= [1, 2]
Output: 1
Explanation: Knight takes 1 step to reach from (3, 3) to (1 ,2).
Input: n = 6, knightPos[] = [1, 3], targetPos[] = [5, 1]
Output: 2
Explanation: In above diagram Knight takes 2 step to reach from (1, 3) to (5, 0): (1, 3) -> (3, 2) -> (5, 1)  
 
Constraints:

n ≤ 1000
2 ≤ knightPos.size(), targetPos.size() ≤ 2
1 ≤ knightPos[i], targetPos[i] ≤ n
*/

class Solution {
public:
    int minStepToReachTarget(vector<int>& knightPos,
                             vector<int>& targetPos,
                             int n) {

        // Convert 1-based indexing to 0-based indexing
        int sx = knightPos[0] - 1;
        int sy = knightPos[1] - 1;

        int tx = targetPos[0] - 1;
        int ty = targetPos[1] - 1;

        // Already at target
        if (sx == tx && sy == ty)
            return 0;

        // 8 possible knight moves
        int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

        // visited[x][y]
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<int, int>> q;

        q.push({sx, sy});
        visited[sx][sy] = true;

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();
            steps++;

            // Process one BFS level
            while (size--) {

                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 8; k++) {

                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    // Check board boundaries
                    if (nx < 0 || nx >= n ||
                        ny < 0 || ny >= n)
                        continue;

                    // Skip already visited cells
                    if (visited[nx][ny])
                        continue;

                    // Target reached
                    if (nx == tx && ny == ty)
                        return steps;

                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};

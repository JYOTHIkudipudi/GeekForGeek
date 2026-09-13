/* Party in Town

Geek Town has n houses numbered from 1 to n, choose a house to host a party such that its distance from its farthest house is as small as possible. 
Return this minimum possible distance.
The houses are connected by n − 1 bidirectional roads, forming a tree. 
The connections are given as an adjacency list adj, where adj[i] contains all houses directly connected to house i + 1. 
Examples:

Input: adj[][] = [[2], [1, 4, 3], [2], [2]] 

Output: 1
Explanation: Party should take place at house number 2. Maximum distance from house number 2 is 1.
Input: adj[][] = [[2], [1, 3], [4, 2], [3]]

Output: 2
Explanation: Party should take place at house number 2 or 3. The minimum distance is 2.
Constraints:

1 ≤ n ≤ 105
1 ≤ adj[i][j]
adj.size() = n  */

class Solution {
  public:
    int bfs(int start, vector<vector<int>> &adj, int n, int &farthest) {
        vector<int> dist(n + 1, -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        farthest = start;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int next : adj[node - 1]) {
                if (dist[next] == -1) {
                    dist[next] = dist[node] + 1;
                    q.push(next);

                    if (dist[next] > dist[farthest]) {
                        farthest = next;
                    }
                }
            }
        }

        return dist[farthest];
    }

    int partyHouse(vector<vector<int>> &adj) {
        int n = adj.size();

        if (n <= 1)
            return 0;

        int A;

        // 1st BFS: find one endpoint of diameter
        bfs(1, adj, n, A);

        int B;

        // 2nd BFS: find diameter length
        int diameter = bfs(A, adj, n, B);

        // Radius = ceil(diameter / 2)
        return (diameter + 1) / 2;
    }
};

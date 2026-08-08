/*  Min Edge Movements to Connect a Graph

Difficulty: **Medium**Accuracy: **52.79%**Submissions: **32K+**Points: **4**Average Time: **30m**

Given a graph with **n** vertices (0 to n-1) and **m** edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation.

Find the minimum number of operations required to connect the graph. If it is not possible to connect the graph, return -1.

**Examples:** 

```
Input: n = 4, edges[][] = [[0, 1], [0, 2], [1, 2]]

Output: 1
Explanation: Remove edge between vertices 1 and 2 and add between vertices 1 and 3.


```

```
Input: n = 6, edges[][] = [[0,1], [0,2], [0,3], [1,2], [1,3]]

Output: 2
Explanation: Remove edge between (1,2) and (0,3), and add edge between (1,4) and (3,5)

```

**Constraints:**

1 ≤ n ≤ 105
1 ≤ m ≤ 105
2 ≤ m (cols) ≤ 2
edges[i][j] < n
edges.rows ≤ m
There are no multi-edges in the graph.

*/

class Solution {
public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        if (edges.size() < n - 1)
            return -1;

        vector<int> parent(n), rank(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        function<int(int)> find = [&](int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return;

            if (rank[a] < rank[b])
                swap(a, b);

            parent[b] = a;

            if (rank[a] == rank[b])
                rank[a]++;
        };

        for (auto &edge : edges) {
            unite(edge[0], edge[1]);
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }

        return components - 1;
    }
};

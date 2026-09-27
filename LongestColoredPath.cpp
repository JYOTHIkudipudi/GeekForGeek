/*  Longest Colored Path
Difficulty: HardAccuracy: 32.64%Submissions: 7K+Points: 8
Given an undirected acyclic graph (tree) with n nodes numbered from 1 to n. Each node is colored either Red (R) or Blue (B).

The colors of the nodes are given by a string s of length n, where:

s[i] = 'R' means node i + 1 is Red.
s[i] = 'B' means node i + 1 is Blue.
You are also given a list of n - 1 edges edges[][], where each edges[i] = [u, v] represents an undirected edge between nodes u and v.

You can start from any node and traverse along the edges to form a path.

A path is called valid if, once you visit a Blue node, you cannot visit any Red node after it on the same path.

In other words, a valid path must have the following form:

Only Red nodes, or
Only Blue nodes, or
Some Red nodes followed by some Blue nodes.
A path containing a pattern like Blue -> Red is invalid.
Find the maximum number of nodes in a valid path.

Examples:

Input: s = "RBB", edges = [[1, 2], [1, 3]] 
  
Output: 2
Explanation: The longest path is either 1 -> 2 or 1 -> 3. In both cases, the length of the path is 2.
Input: s = "BB", edges = [[1, 2]]
  
Output: 2
Explanation: The longest path is 1 -> 2. The length of the path is 2.
Constraints:

s.size() ≤ 105
1 ≤ edges[i][j] ≤ s.size()
s consists only of the characters R and B
edges.size() = s.size()-1  */

class Solution {
public:
    int longestPath(string s, vector<vector<int>>& edges) {

        int n = s.size();

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // --------------------------------------------------
        // Build parent and traversal order
        // --------------------------------------------------

        vector<int> parent(n, -1);
        vector<int> order;

        order.reserve(n);

        stack<int> st;
        st.push(0);
        parent[0] = -2;

        while (!st.empty()) {

            int u = st.top();
            st.pop();

            order.push_back(u);

            for (int v : adj[u]) {

                if (v == parent[u])
                    continue;

                parent[v] = u;
                st.push(v);
            }
        }

        // --------------------------------------------------
        // down[u] = longest same-color path starting at u
        // going downward
        // --------------------------------------------------

        vector<int> down(n, 1);

        for (int i = n - 1; i >= 0; i--) {

            int u = order[i];

            for (int v : adj[u]) {

                if (parent[v] != u)
                    continue;

                if (s[v] == s[u]) {

                    down[u] = max(
                        down[u],
                        1 + down[v]
                    );
                }
            }
        }

        // --------------------------------------------------
        // up[u] = longest same-color path starting at u
        // going through parent side
        // --------------------------------------------------

        vector<int> up(n, 1);

        for (int u : order) {

            // Find the largest and second-largest
            // same-color downward branches.
            int best1 = 0;
            int best2 = 0;
            int bestChild = -1;

            for (int v : adj[u]) {

                if (parent[v] != u)
                    continue;

                if (s[v] != s[u])
                    continue;

                int value = down[v];

                if (value > best1) {
                    best2 = best1;
                    best1 = value;
                    bestChild = v;
                }
                else if (value > best2) {
                    best2 = value;
                }
            }

            for (int v : adj[u]) {

                if (parent[v] != u)
                    continue;

                // Child has different color.
                // It cannot continue the same-color path.
                if (s[v] != s[u]) {
                    up[v] = 1;
                    continue;
                }

                // Best same-color path coming from u.
                int bestFromU = up[u];

                // If v is the child providing best1,
                // use best2 instead.
                if (bestChild == v)
                    bestFromU = max(bestFromU, 1 + best2);
                else
                    bestFromU = max(bestFromU, 1 + best1);

                up[v] = 1 + bestFromU;
            }
        }

        // --------------------------------------------------
        // arm[u] = longest same-color path starting at u
        // --------------------------------------------------

        vector<int> arm(n);

        int answer = 1;

        for (int u = 0; u < n; u++) {

            arm[u] = max(down[u], up[u]);

            answer = max(answer, arm[u]);
        }

        // --------------------------------------------------
        // Every R-B edge can be the unique transition.
        // R arm + B arm
        // --------------------------------------------------

        for (auto &e : edges) {

            int u = e[0] - 1;
            int v = e[1] - 1;

            if (s[u] != s[v]) {

                answer = max(
                    answer,
                    arm[u] + arm[v]
                );
            }
        }

        return answer;
    }
};

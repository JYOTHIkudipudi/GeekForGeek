/*  Largest Sum Cycle

Given an array edge[] of size n, there are n cells numbered from 0 to n - 1. Each cell has at most one outgoing edge.

For every cell i:

edge[i] is the cell reached from i in one step.
edge[i] = -1 means that cell i has no outgoing edge.
A cycle is a sequence of cells where, by following the outgoing edges,
we eventually return to the starting cell. The sum of a cycle is the sum of the indices of all cells in that cycle.

Return the maximum cycle sum. If there is no cycle, return -1.

Examples:

Input: edge[] = [1, 2, 0, -1]
Output: 3
Explanation: There is only one cycle in the graph i.e. 0 -> 1 -> 2 -> 0. Sum of the cell index in that cycle = 0 + 1 + 2 = 3.

Input: edge[] = [2, 0, -1, 2]
Output: -1
Explanation: There is no cycle in the graph. The edges are 1 -> 0 -> 2 <- 3. Hence, 2 has no outgoing edge, so no cycle exists.

Constraints:

2 ≤ edge.size() ≤ 105
-1 ≤ edge[i] < edge.size()
edge[i] != i  */


class Solution {
public:
    int largestSumCycle(vector<int>& edge) {
        int n = edge.size();

        vector<int> visited(n, 0);
        vector<int> pathIndex(n, -1);

        int ans = -1;

        for (int i = 0; i < n; i++) {

            if (visited[i]) continue;

            int node = i;
            int step = 0;

            while (node != -1 && !visited[node]) {

                visited[node] = 1;
                pathIndex[node] = step++;

                node = edge[node];
            }

            // Cycle detected in current traversal
            if (node != -1 && pathIndex[node] != -1) {

                int sum = 0;
                int curr = node;

                do {
                    sum += curr;
                    curr = edge[curr];
                } while (curr != node);

                ans = max(ans, sum);
            }

            // Reset current traversal markers
            node = i;

            while (node != -1 && pathIndex[node] != -1) {
                int next = edge[node];
                pathIndex[node] = -1;
                node = next;
            }
        }

        return ans;
    }
};

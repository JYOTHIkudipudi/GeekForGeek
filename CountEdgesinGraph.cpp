/*  Count Edges in Graph  
Given an undirected graph with V vertices numbered from 0 to V - 1, represented by an adjacency list adj[][], where adj[i] contains the vertices adjacent to vertex i.
Return the total number of edges present in the graph.
Examples:
Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3], [2]]
[image](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/913857/Web/Other/blobid0_1761566038.jpg)
Output: 4 Explanation: The edges in the graph are: (0-1), (0-2), (2-3), (1-2). Hence, total number of edges = 4.

Input: adj[][] = [[1], [0, 2], [1, 3], [2]]
[image](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/913857/Web/Other/blobid1_1761566117.jpg)
Output: 3
Explanation: The edges in the graph are: (0-1), (1-2), (2-3). Hence, total number of edges = 3.

Constraints:
1 ≤ adj.size() ≤ 104
0 ≤ adj[i][j] < adj.size()  
*/


class Solution {
public:
    int countEdges(vector<vector<int>>& adj) {
        int total = 0;

        for (int i = 0; i < adj.size(); i++) {
            total += adj[i].size();
        }

        return total / 2;
    }
};


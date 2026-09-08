/*  Word in Grid - All Occurrences

Given a 2D grid mat[][] of size n × m consisting of characters and a string word, find all starting positions where the word occurs in the grid.

The word can be formed from any cell by moving in any of the 8 directions (2 horizontal, 2 vertical, and 4 diagonal) in a straight line without changing direction.
Each cell can be used at most once per occurrence.
Return all unique starting coordinates in lexicographically smallest order.
Examples :

Input: mat[][] = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}, word = "abe"
Output: {{0,0}, {0,2}, {1,0}}
Explanation: From (0,0) we can find "abe" in right-down diagonal. From (0,2) we can find "abe" in left-down diagonal. From (1,0) we can find "abe" in horizontally right direction.

Input: mat[][] = {{G,E,E,K,S,F,O,R,G,E,E,K,S}, {G,E,E,K,S,Q,U,I,Z,G,E,E,K}, {I,D,E,Q,A,P,R,A,C,T,I,C,E}}, word = "GEEKS"
Output: {{0,0}, {0,8}, {1,0}}
Explanation: From (0,0) we can find "GEEKS" horizontally right. From (0,8) we can find "GEEKS" horizontally right. From (1,0) we can find "GEEKS" horizontally right. 

Constraints:
1 <= n <= m <= 50
1 <= |word| <= 20 */
class Solution {
public:
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        // 8 possible directions
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                // First character must match
                if (mat[i][j] != word[0])
                    continue;
                
                // Try all 8 directions
                for (int d = 0; d < 8; d++) {
                    
                    int x = i;
                    int y = j;
                    int k;
                    
                    for (k = 1; k < word.size(); k++) {
                        x += dx[d];
                        y += dy[d];
                        
                        // Out of bounds
                        if (x < 0 || x >= n || y < 0 || y >= m)
                            break;
                        
                        // Character doesn't match
                        if (mat[x][y] != word[k])
                            break;
                    }
                    
                    // Entire word matched
                    if (k == word.size()) {
                        ans.push_back({i, j});
                        break;  // Don't add same starting cell again
                    }
                }
            }
        }
        
        return ans;
    }
};

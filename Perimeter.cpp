/*  Perimeter of Shapes in Binary Matrix

Given a binary matrix mat[][] of size n × m, where each cell contains either 0 or 1, find the total perimeter of all figures formed by cells containing 1s. Two cells are considered adjacent if they share a common side.

A single cell containing 1 has a perimeter of 4, whereas two adjacent cells containing 1 (i.e., 11) together have a perimeter of 6.

 

Examples :

Input: mat[][] = [[0,1,0,0,0], [1,1,1,0,0], [1,0,0,0,0]]
Output: 12
Explanation: The five cells form a single figure. Hence, the perimeter of the figure is 12.     

Input: mat[][] = [[1,0], [1,1]]
Output: 8
Explanation: The two adjacent cells share one common side. Hence, the perimeter of the figure is 6.  

Constraints:

1 ≤ n, m ≤ 1000   */

```cpp
class Solution {
  public:
    int findPerimeter(vector<vector<int>> &mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        int perimeter = 0;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (mat[i][j] == 1) {
                    
                    // This cell has 4 sides
                    perimeter += 4;
                    
                    // Check all 4 neighbors
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];
                        
                        // If neighboring cell is also 1,
                        // this side is not part of perimeter
                        if (ni >= 0 && ni < n &&
                            nj >= 0 && nj < m &&
                            mat[ni][nj] == 1) {
                            perimeter--;
                        }
                    }
                }
            }
        }
        
        return perimeter;
    }
};
```

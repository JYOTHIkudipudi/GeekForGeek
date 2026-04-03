/*  
Print Diagonally
Difficulty: EasyAccuracy: 66.11%Submissions: 50K+Points: 2Average Time: 10m
Give a n * n square matrix mat[][], return all the elements of its anti-diagonals from top to bottom.

Examples :

Input: n = 2, mat[][] = [[1, 2],
                        [3, 4]]
Output: [1, 2, 3, 4]
Explanation: 

Input: n = 3, mat[][] = [[1, 2, 3],
                       [4, 5, 6],
                       [7, 8, 9]]
Output: [1, 2, 4, 3, 5, 7, 6, 8, 9]
Explanation: 

Constraints:
1 ≤ n ≤ 103
0 ≤ mat[i][j] ≤ 106   */
class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
       int n = mat.size();
        vector<int> res;

        // Start from first row
        for (int col = 0; col < n; col++) {
            int i = 0, j = col;
            while (i < n && j >= 0) {
                res.push_back(mat[i][j]);
                i++;
                j--;
            }
        }

        // Start from last column (excluding first row)
        for (int row = 1; row < n; row++) {
            int i = row, j = n - 1;
            while (i < n && j >= 0) {
                res.push_back(mat[i][j]);
                i++;
                j--;
            }
        }

        return res;
    }

};

/*  Exit Point in a Matrix

Given a matrix mat[][] of size n × m consisting of 0s and 1s. You start at the top-left cell (0, 0) and 
initially move in the left-to-right direction (i.e., towards the right).

While traversing the matrix, follow these rules:

If the current cell contains 0, continue moving in the same direction.
If the current cell contains 1, change your direction to the right (clockwise turn), and update the cell value to 0.
You continue this process until you move outside the boundaries of the matrix. Your task is to determine the coordinates 
(row and column index) of the cell from which you exit the matrix.

Examples:

Input: mat[][] = [[0, 1, 0],
               [0, 1, 1], 
               [0, 0, 0]]
Output: [1, 0]
Explanation: 

From the image we can see that, enter the matrix at (0, 0) 
-> then move towards (0, 1) ->  1 is encountered 
-> turn right towards (1, 1)  -> again 1 is encountered 
-> turn right again towards (1, 0) 
-> now, the boundary of matrix will be crossed. Hence, exit point reached at [1, 0].
Input: mat[][] = [[0, 0]]
Output: [0, 1]
Explanation: 
Enter the matrix at cell (0, 0).
Since the cell contains 0, we continue moving in the same direction.
We reach cell (0, 1), which also contains a 0. So, we continue moving in the same direction, we exit the matrix from cell [0, 1].
Constraints:
1 ≤ n, m ≤ 100

*/
class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int i = 0, j = 0;
        int dir = 0; // 0=Right, 1=Down, 2=Left, 3=Up

        while (i >= 0 && i < n && j >= 0 && j < m) {
            if (mat[i][j] == 1) {
                dir = (dir + 1) % 4; // turn right
                mat[i][j] = 0;
            }

            if (dir == 0) j++;      // Right
            else if (dir == 1) i++; // Down
            else if (dir == 2) j--; // Left
            else i--;               // Up
        }

        // Move back to the last valid cell
        if (dir == 0) j--;
        else if (dir == 1) i--;
        else if (dir == 2) j++;
        else i++;

        return {i, j};
    }
};


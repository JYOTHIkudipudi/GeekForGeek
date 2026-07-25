/*  Max Sum Square Sub-Matrix of Size k

Given a n × n grid mat[][] of integers where values can be negative, find the maximum sum among all possible k × k sub-grids.

Examples:

Input: k = 3, mat[][] = [[1, 2, -1, 4], [-8, -3, 4, 2], [3, 8, 10, -8], [-4, -1, 1, 7]]
Output: 20
Explanation: The 3 × 3 sub-grid [[-3, 4, 2], [8, 10, -8], [-1, 1, 7]] highlighted in red has the maximum sum of 20. 

Input: k = 1, mat[][] = [[4]]
Output: 4
Explanation: Only one 1×1 sub-grid exists with sum 4.

Constraints:

1 ≤ n ≤ 1000
1 ≤ k ≤ n
-1000 ≤ mat[i][j] ≤ 1000  */

class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        
        // prefix[i][j] = sum of submatrix mat[0..i-1][0..j-1]
        vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i-1][j-1] 
                             + prefix[i-1][j] 
                             + prefix[i][j-1] 
                             - prefix[i-1][j-1];
            }
        }
        
        int maxSum = INT_MIN;
        
        // Slide k x k window using prefix sums
        for (int i = k; i <= n; i++) {
            for (int j = k; j <= n; j++) {
                int sum = prefix[i][j] 
                        - prefix[i-k][j] 
                        - prefix[i][j-k] 
                        + prefix[i-k][j-k];
                maxSum = max(maxSum, sum);
            }
        }
        
        return maxSum;
    }
};

/*  Minimum Cost Selection

Given an n × 3 matrix mat[][], where each row represents the costs of three available choices at a shop, select exactly one choice from each row such that the same choice is not selected in two adjacent rows.

Return the minimum total cost required.

Examples:

Input: mat[][] = [[1, 50, 50], [50, 50, 50], [1, 50, 50]]
Output: 52
Explanation: One optimal selection is- Row 1: Choice 1 (Cost = 1), Row 2: Choice 2 (Cost = 50), Row 3: Choice 1 (Cost = 1)
Total cost = 1 + 50 + 1 = 52.
Input: mat[][] = [[1, 4, 1], [3, 2, 2], [3, 2, 3]]
Output: 5
Explanation: One optimal selection is- Row 1: Choice 1 (Cost = 1), Row 2: Choice 2 (Cost = 2), Row 3: Choice 3 (Cost = 2)
Total cost = 1 + 2 + 2 = 5.
Constraints:

1 ≤ n ≤ 105
3 ≤ mat[0].size() ≤ 3
1 ≤ mat[i][j] ≤ 100
mat.rows = n  */
class Solution {
  public:
    int minCost(vector<vector<int>>& mat) {
        int n = mat.size();
        int dp0 = mat[0][0], dp1 = mat[0][1], dp2 = mat[0][2];
        
        for (int i = 1; i < n; i++) {
            int n0 = mat[i][0] + min(dp1, dp2);
            int n1 = mat[i][1] + min(dp0, dp2);
            int n2 = mat[i][2] + min(dp0, dp1);
            dp0 = n0; dp1 = n1; dp2 = n2;
        }
        
        return min({dp0, dp1, dp2});
    }
};

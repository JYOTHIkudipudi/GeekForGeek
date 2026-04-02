/*  Painting the Fence
Given a fence with n posts and k colours, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colours.
Answers are guaranteed to be fit into a 32 bit integer.

Examples:

Input: n = 3, k = 2 
Output: 6
Explanation: Let the 2 colours be 'R' and 'B'. We have following possible combinations:
1. RRB
2. RBR
3. RBB
4. BRR
5. BRB
6. BBR
Input: n = 2, k = 4 
Output: 16
Explanation: After coloring first post with 4 possible combinations, you can still color next posts with all 4 colors. Total possible combinations will be 4x4=16
Constraints:
1 ≤ n ≤ 300
1 ≤ k ≤ 105    */

class Solution {
  public:
    int countWays(int n, int k) {
        // code here
    if (n == 1) return k;

    int same = k;           // for n=2 (AA)
    int diff = k * (k - 1); // for n=2 (AB)

    for (int i = 3; i <= n; i++) {
        int newSame = diff;
        int newDiff = (same + diff) * (k - 1);

        same = newSame;
        diff = newDiff;
    }

    return same + diff;

    }
};  

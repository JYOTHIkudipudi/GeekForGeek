/* Box Stacking

Given three arrays height[], width[], and length[] of size n, where height[i], width[i], and length[i] represent the dimensions of the ith box, 
find the maximum possible height of a stack formed using these boxes.

A box can be rotated so that any of its dimensions becomes its height.
 A box can be placed on top of another only if both dimensions of its base are strictly smaller than those of the box below. 
Multiple instances of the same box can be used.
Examples:

Input: height[] = [4, 1, 4, 10], width[] = [6, 2, 5, 12], length[] = [7, 3, 6, 32]
Output: 60
Explanation: One possible arrangement of the boxes from bottom to top is shown below. Note that there can be multiple instances of a box type.
 
Hence, the total height of this stack is 10 + 32 + 4 + 4 + 6 + 1 + 3 = 60. No other combination of boxes produces a height greater than this.
Input: height[] = [1, 4, 3], width[] = [2, 5, 4], length[] = [3, 6, 1]
Output: 15
Explanation: One possible arrangement of the boxes from bottom to top is shown below: 

Hence, the total height of this stack is 4 + 6 + 1 + 1 + 3 = 15 No other combination of boxes produces a height greater than this.
Constraints:

1 ≤ height.size(), width.size(), length.size() ≤ 100
1 ≤ height[i], width[i], length[i] ≤ 106
*/


class Solution {
public:
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        int n = height.size();

        // Each rotation: {base1, base2, height}
        vector<array<int, 3>> boxes;

        for (int i = 0; i < n; i++) {
            boxes.push_back({max(width[i], length[i]), min(width[i], length[i]), height[i]});
            boxes.push_back({max(height[i], length[i]), min(height[i], length[i]), width[i]});
            boxes.push_back({max(height[i], width[i]), min(height[i], width[i]), length[i]});
        }

        int m = boxes.size();
        vector<int> dp(m);

        // dp[i] = maximum height of a stack whose bottom box is rotation i
        function<int(int)> solve = [&](int i) -> int {
            if (dp[i]) return dp[i];

            dp[i] = boxes[i][2];

            for (int j = 0; j < m; j++) {
                // j can be placed on i
                if (boxes[j][0] < boxes[i][0] &&
                    boxes[j][1] < boxes[i][1]) {
                    dp[i] = max(dp[i], boxes[i][2] + solve(j));
                }
            }

            return dp[i];
        };

        int ans = 0;
        for (int i = 0; i < m; i++)
            ans = max(ans, solve(i));

        return ans;
    }
};

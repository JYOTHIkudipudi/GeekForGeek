/* Maximum Height Disc Stack

Given two arrays r[] and h[] of size n, where r[i] and h[i] represent the radius and height of the i-th circular disc, respectively.

A disc can be placed above another disc only if both its radius and height are strictly smaller than those of the disc below it.

Find the maximum possible height of a stack that can be formed using the given discs. Each disc can be used at most once.

Examples:

Input: r[] = [5, 7, 3], h[] = [6, 5, 4]
Output: 10
Explanation: The discs (3, 4) and (5, 6) form a valid stack. Therefore, the maximum possible height is 4 + 6 = 10.
Input: r[] = [3, 7], h[] = [7, 4]
Output: 7
Explanation: Neither disc can be placed above the other because both required dimensions are not strictly smaller. Therefore, the maximum possible height is 7.
Constraints:

1 ≤ r.size(), h.size() ≤ 105
1 ≤ r[i], h[i] ≤ 1000 */

class Solution {
public:
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        int n = r.size();

        vector<pair<int, int>> discs;
        for (int i = 0; i < n; i++) {
            discs.push_back({r[i], h[i]});
        }

        sort(discs.begin(), discs.end());

        vector<int> dp(n);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            dp[i] = discs[i].second;

            for (int j = 0; j < i; j++) {
                if (discs[j].first < discs[i].first &&
                    discs[j].second < discs[i].second) {
                    dp[i] = max(dp[i], dp[j] + discs[i].second);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

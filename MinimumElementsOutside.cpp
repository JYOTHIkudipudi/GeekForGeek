/* Minimum Elements Outside Subsequences

Given an array arr[] of size n, partition its elements into a strictly increasing subsequence and a strictly decreasing subsequence.

Each element can belong to at most one of these subsequences, and some elements may remain unused.

Determine the minimum number of elements that cannot be included in either subsequence.

Examples:

Input: arr[] = [7, 8, 1, 2, 4, 6, 3, 5, 2, 1, 8, 7]
Output: 2
Explanation: One possible increasing subsequence is: [1, 2, 4, 5, 8]. One possible decreasing subsequence is: [7, 6, 3, 2, 1]. The remaining elements are 8 and 7, so the minimum number of unselected elements is 2.
Input: arr[] = [1, 4, 2, 3, 3, 2, 4]
Output: 0
Explanation: One possible increasing subsequence is: [1, 2, 3, 4]. One possible decreasing subsequence is: [4, 3, 2]. All elements are included in one of the two subsequences.

Constraints:
1 ≤ n ≤ 100
1 ≤ arr[i] ≤ 100

*/

class Solution {
  public:
    int minCount(vector<int>& arr) {
        int n = arr.size();

        // dp[i][j] = maximum elements selected so far
        // i = last index used in increasing subsequence
        // j = last index used in decreasing subsequence
        //
        // -1 means that subsequence is still empty.
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // +1 is used because index -1 is stored as 0.
        dp[0][0] = 0;

        for (int k = 0; k < n; k++) {

            // Copy current states before processing arr[k]
            vector<vector<int>> ndp = dp;

            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {

                    if (dp[i][j] == -1)
                        continue;

                    int inc = i - 1;
                    int dec = j - 1;

                    // 1. Put arr[k] in increasing subsequence
                    if (inc == -1 || arr[k] > arr[inc]) {
                        int ni = k + 1;

                        ndp[ni][j] = max(
                            ndp[ni][j],
                            dp[i][j] + 1
                        );
                    }

                    // 2. Put arr[k] in decreasing subsequence
                    if (dec == -1 || arr[k] < arr[dec]) {
                        int nj = k + 1;

                        ndp[i][nj] = max(
                            ndp[i][nj],
                            dp[i][j] + 1
                        );
                    }

                    // 3. Don't use arr[k]
                    // Already handled by copying dp -> ndp.
                }
            }

            dp = ndp;
        }

        int selected = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                selected = max(selected, dp[i][j]);
            }
        }

        return n - selected;
    }
};

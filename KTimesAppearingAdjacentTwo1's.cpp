/*  k Times Appearing Adjacent Two 1's

Given two integers n and k, count the number of binary strings of length n where adjacent 1 appear k times.

Since the answer can be huge, return it modulo 109+7.

Examples:

Input: n = 3, k = 2
Output: 1
Explanation: Possible string is "111" where 2 adjacent 1 appear.
Input: n = 5, k = 2
Output: 6
Explanation: Possible strings are "00111", "10111", "01110", "11100", "11101" and "11011".
Constraints:
1 ≤ n, k ≤ 103  */

class Solution {
public:
    const int MOD = 1e9 + 7;

    int countStrings(int n, int k) {

        vector<vector<int>> prev(k + 1, vector<int>(2, 0));
        vector<vector<int>> cur(k + 1, vector<int>(2, 0));

        prev[0][0] = 1;
        prev[0][1] = 1;

        for (int len = 2; len <= n; len++) {

            for (int j = 0; j <= k; j++) {
                cur[j][0] = 0;
                cur[j][1] = 0;
            }

            for (int j = 0; j <= k; j++) {

                // End with 0
                cur[j][0] = (prev[j][0] + prev[j][1]) % MOD;

                // End with 1 after 0
                cur[j][1] = prev[j][0];

                // End with 1 after 1
                if (j > 0)
                    cur[j][1] = (cur[j][1] + prev[j - 1][1]) % MOD;
            }

            swap(prev, cur);
        }

        return (prev[k][0] + prev[k][1]) % MOD;
    }
};

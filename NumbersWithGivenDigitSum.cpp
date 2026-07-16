/*  Numbers with Given Digit Sum

Given two integers n and sum, determine the number of n-digit positive integers whose digits add up to sum.

An n-digit number cannot have leading zeros; that is, the first digit must be between 1 and 9.
If there exist no n digit number with sum of digits equal to given sum, return -1.
Examples :

Input: n = 2, sum = 2
Output: 2
Explaination: The valid 2-digit numbers whose digits sum to 2 are 11 and 20.
Input: n = 1, sum = 10
Output: -1
Explaination: A single-digit number can only have a digit sum between 0 and 9.
Input: n = 2, sum = 10
Output: 9
Explaination: The 2-digit numbers whose digits add up to 10 are: 19, 28, 37, 46, 55, 64, 73, 82, 91.
Constraints:
1 ≤ n ≤ 9
1 ≤ sum ≤ 81  */

class Solution {
    int dp[10][82];

    int solve(int pos, int rem, int n) {
        if (rem < 0) return 0;
        if (pos == n) return (rem == 0);

        if (dp[pos][rem] != -1)
            return dp[pos][rem];

        int ans = 0;
        int start = (pos == 0) ? 1 : 0; // First digit cannot be 0

        for (int d = start; d <= 9; d++) {
            ans += solve(pos + 1, rem - d, n);
        }

        return dp[pos][rem] = ans;
    }

public:
    int countWays(int n, int sum) {
        // Impossible cases
        if (sum < 1 || sum > 9 * n)
            return -1;

        memset(dp, -1, sizeof(dp));

        int ans = solve(0, sum, n);

        return (ans == 0) ? -1 : ans;
    }
};

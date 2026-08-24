/* Count Prefix-Balanced Binary Strings

Given an integer n, count the number of binary strings of length 2 * n that contain exactly n ones and n zeros such that every prefix of the string contains at least as many ones as zeros. Since the answer can be very large, return it modulo 109 + 7.

Examples:

Input: n = 2
Output: 2
Explanation: "1100", "1010" are two such strings of size 4 which have exactly two 1's in each.
Input: n = 3
Output: 5
Explanation: "111000", "101100", "101010", "110010", "110100" are such 5 strings which have exactly three 1's in each.
Constraints:

1 ≤ n ≤ 1000  */
class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1)
                ans = (ans * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return ans;
    }

    int prefixStrings(int n) {
        int N = 2 * n;

        vector<long long> fact(N + 1, 1);

        // Calculate factorials
        for (int i = 1; i <= N; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        // Catalan = (2n)! / (n! * n! * (n+1))
        long long denominator =
            (fact[n] * fact[n]) % MOD;

        denominator =
            (denominator * (n + 1)) % MOD;

        long long ans =
            fact[2 * n] * power(denominator, MOD - 2) % MOD;

        return ans;
    }
};

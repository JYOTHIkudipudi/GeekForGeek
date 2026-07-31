/*  Subsets with Products of Distinct Primes
Given an integer array arr[], count the number of different subsets whose product can be represented as a product of one or more distinct prime numbers.  
Two subsets are considered different if the set of chosen array indexes are not same.

Return the count modulo 109 + 7.

Examples:

Input: arr[] = [1, 2, 3, 4]
Output: 6
Explanation: 
The subsets are:
[2], product = 2 = 2
[3], product = 3 = 3
[1, 2], product = 2 = 2
[1, 3], product = 3 = 3
[2, 3], product = 6 = 2 × 3
[1, 2, 3], product = 6 = 2 × 3
All these products can be expressed as a product of one or more distinct prime numbers. Hence, the count is 6.
Note that [4] or any other subset with 4 are not chosen because prducts having 4 have repeated primes 2.
Input: arr[] = [2, 2, 3]
Output: 5
Explanation: 
Since subsets formed using different indices are considered different, the chosen subsets are:
[2] (using the first 2)
[2] (using the second 2)
[3]
[2, 3] (using the first 2)
[2, 3] (using the second 2)
Each subset has a product that can be expressed as a product of one or more distinct prime numbers. 
Therefore, the answer is 5.

Constraints:

1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 30
 */
class Solution {
public:
    static const int MOD = 1000000007;

    int countSubsets(vector<int> &arr) {
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};

        vector<int> mask(31, -1);

        for (int x = 2; x <= 30; x++) {
            int t = x;
            int m = 0;
            bool ok = true;

            for (int i = 0; i < 10; i++) {
                int cnt = 0;
                while (t % primes[i] == 0) {
                    cnt++;
                    t /= primes[i];
                }
                if (cnt > 1) {
                    ok = false;
                    break;
                }
                if (cnt == 1)
                    m |= (1 << i);
            }

            if (ok) mask[x] = m;
        }

        vector<long long> dp(1 << 10, 0);
        dp[0] = 1;

        int ones = 0;

        for (int x : arr) {
            if (x == 1) {
                ones++;
                continue;
            }

            if (mask[x] == -1) continue;

            int m = mask[x];

            for (int s = (1 << 10) - 1; s >= 0; s--) {
                if ((s & m) == 0) {
                    dp[s | m] = (dp[s | m] + dp[s]) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int s = 1; s < (1 << 10); s++)
            ans = (ans + dp[s]) % MOD;

        long long mul = 1;
        while (ones--)
            mul = (mul * 2) % MOD;

        return (ans * mul) % MOD;
    }
};

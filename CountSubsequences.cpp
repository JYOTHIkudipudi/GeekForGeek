/*  Count Subsequences Divisible by n

Given a numeric string s containing only digits and an integer n, count the number of non-empty subsequences of s whose numeric value is divisible by n.
Return the answer modulo 1e9 + 7.

Examples:

Input: s = "1234", n = 4
Output: 4
Explanation: The subsequences 4, 12, 24 and 124 are divisible by 4.
Input: s = "330", n = 6
Output: 4
Explanation: The subsequences 30, 30, 330 and 0 are divisible by 6.
Constraints:
1 ≤ |s| * n ≤ 106  */

class Solution {
public:
    int countSubsequences(string& s, int n) {
        
        const int MOD = 1e9 + 7;
        
        // dp[r] = number of non-empty subsequences
        // whose remainder is r
        vector<long long> dp(n, 0);
        
        for (char ch : s) {
            
            int digit = ch - '0';
            
            // Keep old subsequences (don't take current digit)
            vector<long long> ndp = dp;
            
            // Start a new subsequence with current digit
            int rem = digit % n;
            ndp[rem] = (ndp[rem] + 1) % MOD;
            
            // Append current digit to every existing subsequence
            for (int r = 0; r < n; r++) {
                
                if (dp[r] == 0)
                    continue;
                
                int newRem = (r * 10 + digit) % n;
                
                ndp[newRem] = (ndp[newRem] + dp[r]) % MOD;
            }
            
            dp = ndp;
        }
        
        // Remainder 0 => divisible by n
        return dp[0];
    }
};

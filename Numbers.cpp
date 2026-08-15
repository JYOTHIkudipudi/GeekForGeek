/* Numbers Without d as Digit

Given a number n, count the numbers from 1 to n that don’t contain digit d in their decimal representation.

Examples:

Input: n = 25, d = 3
Output: 22
Explanation: From 1 to 25, the numbers 3, 13, and 23 contain the digit 3, so the answer is 25 - 3 = 22.
Input: n = 5, d = 3
Output: 4
Explanation: From 1 to 5, only 3 contains the digit 3, so the count of numbers without digit 3 is 4.
Constraints:

0 ≤ n ≤ 109
0 ≤ d ≤ 9  */

class Solution {
  public:
    int countWithout(int n, int d) {
        string digits = to_string(n);
        int len = digits.size();
        
        // dp[pos][started] - memo only valid for tight=false
        vector<vector<long long>> dp(len + 1, vector<long long>(2, -1));
        
        function<long long(int, bool, bool)> go = [&](int pos, bool started, bool tight) -> long long {
            if (pos == len) return 1;
            if (!tight && dp[pos][started] != -1) return dp[pos][started];
            
            int limit = tight ? (digits[pos] - '0') : 9;
            long long res = 0;
            
            for (int dig = 0; dig <= limit; dig++) {
                bool isRealDigit = started || (dig != 0);
                if (dig == d && isRealDigit) continue; // skip forbidden digit
                
                bool newStarted = started || (dig != 0);
                bool newTight = tight && (dig == limit);
                res += go(pos + 1, newStarted, newTight);
            }
            
            if (!tight) dp[pos][started] = res;
            return res;
        };
        
        long long total = go(0, false, true); // counts 0..n, including "0" itself
        return (int)(total - 1); // exclude 0, since we want count in [1, n]
    }
};

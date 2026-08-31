class Solution {
public:
    int minCost(int n, int i, int d, int c) {
        
        vector<int> dp(n + 1, INT_MAX);
        
        dp[0] = 0;
        
        for (int x = 1; x <= n; x++) {
            
            // Option 1: Insert one character
            dp[x] = dp[x - 1] + i;
            
            // Option 2: Use copy-paste
            if (x % 2 == 0) {
                // x/2 -> x
                dp[x] = min(dp[x], dp[x / 2] + c);
            }
            else {
                // (x+1)/2 -> x+1 -> x
                dp[x] = min(dp[x],
                            dp[(x + 1) / 2] + c + d);
            }
        }
        
        return dp[n];
    }
};

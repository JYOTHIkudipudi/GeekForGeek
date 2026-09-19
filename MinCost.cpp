/* ### Min Cost To Make Two Strings Identical


Given two strings **s1** and **s2**, and two integers **costS1** and **costS2**, where costS1 is the cost of deleting one character from s1 and costS2
is the cost of deleting one character from s2, find the minimum cost required to make the two strings identical.

You can delete any number of characters from either string, but the order of the remaining characters must be preserved.

**Examples:**

**Input:** s1 = "abcd", s2 = "acdb", costS1 = 10, costS2 = 20 **Output:** 30 **Explanation:&#x20;**&#x44;elete 'b' from both strings to obtain "acd". 
The total cost is 10 + 20 = 30.

**Input:&#x20;**&#x73;1 = "ef", s2 = "gh", costS1 = 10, costS2 = 20 **Output:&#x20;**&#x36;0 **Explanation:&#x20;**&#x54;he two strings have no common characters,
so delete all characters from both strings. The total cost is (2 × 10) + (2 × 20) = 60.&#x20;

**Constraints:**

1 ≤ s1.size(), s2.size() ≤ 1000\
1 ≤ costS1, costS2 ≤ 105\

*/

class Solution {
public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Find LCS
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcs = dp[n][m];

        int deleteFromS1 = n - lcs;
        int deleteFromS2 = m - lcs;

        return deleteFromS1 * costS1 + deleteFromS2 * costS2;
    }
};

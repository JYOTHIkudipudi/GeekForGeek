/*  Maximum Weight Transformation of String

Given a string s consisting only of the characters 'A' and 'B', you can toggle any character. A toggle changes 'A' to 'B' or 'B' to 'A'.

The weight of a string is calculated using the following rules:

An alternating adjacent pair ("AB" or "BA") contributes 4 to the weight.
Each character can belong to at most one pair, so the pairs must not overlap.
Every character that does not belong to any pair contributes 1 to the weight.
Each toggle performed decreases the total weight by 1.
Therefore, Weight = Weight of alternating adjacent pairs + Weight of characters that do not belong to any pair - Number of Toggles

You can toggle characters to make adjacent characters different and form pairs. Find the maximum possible weight obtainable from the string by choosing pairs
and toggling characters optimally.

Examples:
Input: s = "AA"
Output: 3
Explanation: The possible transformed strings are "AA", "AB", "BA", and "BB". The strings "AB" and "BA" each contain one alternating adjacent pair, 
contributing 4 to the weight. One toggle is required to obtain either string from "AA", reducing the weight by 1. Therefore, the maximum weight is 4 - 1 = 3.
Input: s = "ABB"
Output: 5
Explanation: Possible transformations are "ABB", "ABA", "AAB", "AAA", "BBB", "BBA", "BAB" and "BAA". The original string "ABB" 
contains the alternating adjacent pair "AB", 
contributing 4 to the weight, while the remaining character 'B' contributes 1. No toggles are required. Therefore, the maximum weight is 4 + 1 = 5.
Constraints:

1 ≤ s.size() ≤ 105
s consists only of the characters A and B  */

class Solution {
  public:
    int getMaxWeight(string &s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            int gain = (s[i - 2] == s[i - 1]) ? 1 : 2;
            dp[i] = max(dp[i - 1], dp[i - 2] + gain);
        }

        return n + dp[n];
    }
};s



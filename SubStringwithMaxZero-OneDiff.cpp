/*  Substring with Max Zero-One Diff
Given a binary string s consisting of 0s and 1s. 
Find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) in a substring of the string.

Note: In the case of all 1s, the answer will be -1.

Examples:

Input : s = "11000010001" 
Output : 6 
Explanatio: From index 2 to index 9, there are 7 0s and 1 1s, so number of 0s - number of 1s is 6. 
Input: s = "111111"
Output: -1
Explanation: s contains 1s only 
Constraints:
1 ≤ s.size() ≤ 105   */
class Solution {
  public:
    int maxSubstring(string &s) {
        int curr = 0, maxi = INT_MIN;

        for(char c : s) {
            int val = (c == '0') ? 1 : -1;

            curr = max(val, curr + val);
            maxi = max(maxi, curr);
        }

        return (maxi <= 0) ? -1 : maxi;
    }
};

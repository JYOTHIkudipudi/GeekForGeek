/*   Choose and Swap

Given a string s of lowercase English letters, you can swap all occurrences of any two distinct characters at most once.
Return the lexicographically smallest string after this operation.
Examples:

Input: s = "ccad"
Output: "aacd"
Explanation: In ccad, we choose a and c and after doing the replacement operation once, we get aacd and this is the lexicographically smallest string possible. 
Input: s = "abba"
Output: "abba"
Explanation: In abba, we can get baab after doing the replacement operation once for a and b but that is not lexicographically smaller than abba. So, the answer is abba. 
Constraints:
1 ≤ |s| ≤ 105  */

class Solution {
public:
    string chooseSwap(string &s) {
        vector<int> first(26, -1);

        // Store first occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
        }

        // Find the first beneficial swap
        for (int i = 0; i < s.size(); i++) {
            int cur = s[i] - 'a';

            // Look for a smaller character occurring later
            for (int j = 0; j < cur; j++) {
                if (first[j] > first[cur]) {
                    char c1 = s[i];
                    char c2 = char(j + 'a');

                    // Swap all occurrences
                    for (char &ch : s) {
                        if (ch == c1)
                            ch = c2;
                        else if (ch == c2)
                            ch = c1;
                    }

                    return s;
                }
            }
        }

        return s;
    }
};

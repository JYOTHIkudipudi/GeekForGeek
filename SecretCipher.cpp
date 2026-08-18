/* Secret Cipher
Difficulty: HardAccuracy: 49.98%Submissions: 12K+Points: 8Average Time: 30m
Geek wants to send a secret message to his friend Keeg. Instead of sending the original message directly, he encrypts it by inserting the character '*'.

Keeg decodes the message as follows:

Traverse the encoded string from left to right and initialize the original string as empty.
Whenever a normal character appears, append it to the current original string.
Whenever '*' is encountered, remove it and append all characters before it to the end of the current original string.
Repeat until no '*' remains.

Given the original string s, find the lexicographically smallest encrypted string that decodes to s.

Examples :

Input: s = "ababcababcd"
Output: ab*c*d
Explanation: We can encrypt the string in following way : "ababcababcd" -> "ababc*d" -> "ab*c*d"
Input: s = "zzzzzzz"
Output: z*z*z
Explanation: The string can be encrypted in 2 ways: "z*z*z" and "z**zzz". Out of the two "z*z*z" is smaller in length.
Constraints: 
1 ≤ |s| ≤ 105   */

class Solution {
public:
    string compress(string &s) {
        int n = s.size();

        // LPS array
        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];

            while (j > 0 && s[i] != s[j])
                j = lps[j - 1];

            if (s[i] == s[j])
                j++;

            lps[i] = j;
        }

        string ans;

        // Build answer from right to left
        int i = n - 1;

        while (i >= 0) {
            // Only even length prefixes can be compressed
            if (i % 2 == 1) {
                int len = i + 1;

                // Check whether this prefix can be represented
                // as two identical parts
                if (lps[i] >= len / 2 &&
                    len % (2 * (len - lps[i])) == 0) {

                    ans += '*';

                    // Move to the first half
                    i = i / 2;
                    continue;
                }
            }

            ans += s[i];
            i--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
    */

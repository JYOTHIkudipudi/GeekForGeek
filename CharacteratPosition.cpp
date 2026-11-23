/*  Character at Position in Infinite String

Given a string s and an integer pos, an infinite string is constructed by repeatedly applying the following operation. 
In the i-th step, append i consecutive $ characters, followed by the reverse of the current string, to the current string.

Formally, if the current string is s, update it as:

s = s + ('$' repeated i times) + reverse(s)
The initial string is the given s, and the process continues indefinitely.

Find and return the character at the pos(1-based indexing) in the resulting infinite string.

Examples:

Input: s = "12345", pos = 3
Output: 3
Explanation: In "12345...", the character at pos 3 is 3.
Input: s = "12345", pos = 10
Output: 2
Explanation: In "12345$54321...", the character at pos 10 is 2.
Input: s = "abc", pos = 7
Output: a
Explanation: In "abc$cba...", the character at pos 7 is a.
Constraints:

1 ≤ s.size() ≤ 105
1 ≤ pos ≤ 109
s consists of English alphabets and digits   */


class Solution {
public:
    char posInfinite(string &s, int pos) {

        vector<long long> len;
        len.push_back(s.size());

        long long p = pos;

        // Phase 1: Calculate lengths
        int i = 1;

        while (len.back() < p) {
            long long L = len.back();

            len.push_back(2 * L + i);
            i++;
        }

        // Phase 2: Trace position backwards
        for (int j = len.size() - 1; j >= 1; j--) {

            long long L = len[j - 1];
            long long step = j;

            if (p <= L) {
                continue;
            }

            else if (p <= L + step) {
                return '$';
            }

            else {
                p = 2 * L + step - p + 1;
            }
        }

        return s[p - 1];
    }
};


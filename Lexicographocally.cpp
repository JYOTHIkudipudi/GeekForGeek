/*  Lexicographically Smallest Rotation

Given a string s, find the lexicographically smallest string after rotating the string left any number of times including 0.

Example:

Input: s = "abcd"
Output: "abcd"
Explanation: String after each rotation are "abcd", "bcda", "cdab", "dabc" and so on. Lexicographically smallest among them is "abcd".


Input: s = "baca"
Output: "abac"
Explanation: Strings after each rotation are "baca", "acab", "caba", "abac" and so on. Lexicographically smallest among them is "abac".

Constraints:

1 ≤ s.size() ≤ 106
s consists only of lowercase English alphabets  */

class Solution {
public:
    string lexiString(string &s) {
        int n = s.size();

        if (n == 1)
            return s;

        int i = 0;
        int j = 1;
        int k = 0;

        while (i < n && j < n && k < n) {

            char a = s[(i + k) % n];
            char b = s[(j + k) % n];

            if (a == b) {
                k++;
            }
            else if (a > b) {
                i = i + k + 1;

                if (i == j)
                    i++;

                k = 0;
            }
            else {
                j = j + k + 1;

                if (i == j)
                    j++;

                k = 0;
            }
        }

        int start = min(i, j);

        return s.substr(start) + s.substr(0, start);
    }
};

/* Check Repeated Substring with K Replacements

Given a string s and an integer k, check if it is possible to convert s to a string that is repetition of a substring with k characters else returns false. 
In order to convert we can replace one substring of length k with any k characters.

Note:  In one operation, you can replace any substring of length k whose starting index i (0-based) satisfies i % k == 0 with any sequence of k characters.

Examples:

Input: s = "abcbedabcabc",  k = 3
Output: true
Explanation: Replace "bed" with "abc" so that the whole string becomes repetition of "abc".
Input: s = "bdac", k = 2
Output: true
Explanation: The string can be divided into substrings of length k: ["bd", "ac"]. 
Since there are exactly two substrings and both are different, we can make them identical by replacing one substring with the other. Hence, the result is true.
Input: s = "abcdabcd", k = 2
Output: false
Explanation: Since we are allowed to change only one instance, we cannot covert.
Constraints:
2 ≤ k ≤ s.size() ≤ 105   */
class Solution {
public:
    bool kSubstr(string &s, int k) {
        int n = s.size();

        if (n % k != 0)
            return false;

        unordered_map<string, int> mp;

        for (int i = 0; i < n; i += k) {
            mp[s.substr(i, k)]++;
        }

        int blocks = n / k;

        // Already a repetition
        if (mp.size() == 1)
            return true;

        // Special case: exactly two blocks
        if (blocks == 2)
            return true;

        if (mp.size() != 2)
            return false;

        for (auto &p : mp) {
            if (p.second == 1)
                return true;
        }

        return false;
    }
};

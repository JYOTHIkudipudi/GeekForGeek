/*  Count Group Occurrences

Given a string s and an integer k, count the number of distinct characters that appear in exactly k groups in the string.

A group is defined as one or more consecutive occurrences of the same character.
For example, in the string "aaabbcca", the groups are "aaa", "bb", "cc" and "a".

Examples:

Input: s = "abc", k = 1
Output: 3
Explanation: The characters 'a', 'b' and 'c' each appear in exactly one group.
Input: s = "geeksforgeeks", k = 2
Output: 4
Explanation: The characters 'g', 'e', 'k' and 's' each appear in exactly two groups.
Input: s = "aaaaa", k = 2
Output: 0
Explanation: The character 'a' appears in only one group, so no character appears in exactly two groups.
Constraints:
1 ≤ s.size() ≤ 105
1 ≤ k ≤ 103
s consists only of lowercase English alphabets  */
class Solution {
  public:
    int getCount(string &s, int k) {

        int freq[26] = {0};

        for(int i = 0; i < s.size(); i++) {

            if(i == 0 || s[i] != s[i-1]) {
                freq[s[i] - 'a']++;
            }
        }

        int ans = 0;

        for(int i = 0; i < 26; i++) {
            if(freq[i] == k) {
                ans++;
            }
        }

        return ans;
    }
};


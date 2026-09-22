/* Longest Matching in Dictionary with Removals

Given a lowercase string s and a dictionary d[] containing lowercase words, find the longest word in the dictionary that can be obtained
by deleting some characters from s without changing the order of the remaining characters.

Note: If multiple words have the same maximum length, return the lexicographically smallest one. If no valid word exists, return an empty string.

Examples : 

Input: d = ["ale", "apple", "monkey", "plea"], s = "abpcplea"
Output: "apple" 
Explanation: After deleting "b", "c", "a" s became "apple" which is present in d.
Input: d = ["a", "b", "c"], s = "abpcplea"
Output: "a"
Explanation: After deleting "b", "p", "c", "p", "l", "e", "a" s became "a" which is present in d.
Constraints:
1 ≤ |s| ≤ 5 * 105
1 ≤ n ≤ 104, where n is the number of words in dictionary
1 ≤ m ≤ 100, where m is the length of word in dictionary
s and all words in dictionary consist only of lowercase English letters.

*/
class Solution {
public:
    string findLongestWord(string &s, vector<string> &d) {
        
        // Store positions of every character in s
        vector<int> pos[26];

        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }

        string ans = "";

        for (string &word : d) {
            
            int prev = -1;
            bool possible = true;

            for (char c : word) {
                
                int ch = c - 'a';

                // Find first occurrence of c after prev
                auto it = upper_bound(
                    pos[ch].begin(),
                    pos[ch].end(),
                    prev
                );

                if (it == pos[ch].end()) {
                    possible = false;
                    break;
                }

                prev = *it;
            }

            if (possible) {
                
                // Longer word
                if (word.size() > ans.size()) {
                    ans = word;
                }
                
                // Same length -> lexicographically smaller
                else if (word.size() == ans.size() && word < ans) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};

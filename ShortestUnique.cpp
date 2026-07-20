/*  Shortest Unique Prefix for Every Word

Given an array of strings arr[ ], find the shortest prefix of each string that uniquely identifies it among all strings in the array. 
A prefix is unique if it is not a prefix of any other string in the array.

Note: No string in the given array is a prefix of another string.

Examples :

Input: arr[] = ["zebra", "dog", "duck", "dove"]
Output: ["z", "dog", "du", "dov"]
Explanation: z => zebra, dog => dog, duck => du, dove => dov 
Input: arr[] = ["geeksgeeks", "geeksquiz", "geeksforgeeks"]
Output: ["geeksg", "geeksq", "geeksf"]
Explanation: geeksgeeks => geeksg, geeksquiz => geeksq, geeksforgeeks => geeksf
Constraints:

1 ≤ |arr| ≤ 1000
1 ≤ |arr[i]| ≤ 1000  */

class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        int cnt;

        TrieNode() {
            cnt = 0;
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };

    vector<string> findPrefixes(vector<string>& arr) {
        TrieNode* root = new TrieNode();

        // Insert all words
        for (string &word : arr) {
            TrieNode* node = root;
            for (char ch : word) {
                int idx = ch - 'a';
                if (node->child[idx] == NULL)
                    node->child[idx] = new TrieNode();

                node = node->child[idx];
                node->cnt++;
            }
        }

        vector<string> ans;

        // Find shortest unique prefix
        for (string &word : arr) {
            TrieNode* node = root;
            string prefix = "";

            for (char ch : word) {
                prefix += ch;
                node = node->child[ch - 'a'];

                if (node->cnt == 1)
                    break;
            }

            ans.push_back(prefix);
        }

        return ans;
    }
};

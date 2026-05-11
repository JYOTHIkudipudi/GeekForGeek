/*  Palindrome Pairs

Given an array arr[] consisting of n strings. Determine whether there exists a pair of indices (i, j) such that i ≠ j and the 
concatenation arr[i] + arr[j] forms a palindrome.

Return true if such a pair exists; otherwise, return false.

Note: A string is considered a palindrome if it reads the same forward and backward.

Examples:

Input: arr[] = ["geekf", "geeks", "or", "keeg", "abc", "bc"]
Output: true
Explanation: There is a pair "geekf" and "keeg". Their concatenation "geekfkeeg" is a palindrome.
Input: arr[] = ["abc", "xyxcba", "geekst", "or", "bc"]
Output: true
Explanation: There is a pair "abc" and "xyxcba". Their concatenation "abcxyxcba" is a palindrome.
Input: arr[] = ["aa"]
Output: false
Explanation: There is only one string present, so the output is false.
Constraints:
1 ≤ n ≤ 2*104
1 ≤ |arr[i]| ≤ 10  */


class Solution {
  public:
    bool palindromePair(vector<string>& arr) {
        unordered_set<string> wordSet(arr.begin(), arr.end());
        
        for (string& word : arr) {
            int len = word.length();
            
            for (int k = 0; k <= len; k++) {
                string prefix = word.substr(0, k);
                string suffix = word.substr(k);
                
                // If prefix is palindrome, check if reverse(suffix) exists
                if (isPalindrome(prefix)) {
                    string revSuffix = suffix;
                    reverse(revSuffix.begin(), revSuffix.end());
                    if (wordSet.count(revSuffix) && revSuffix != word) {
                        return true;
                    }
                }
                
                // If suffix is palindrome, check if reverse(prefix) exists
                if (isPalindrome(suffix)) {
                    string revPrefix = prefix;
                    reverse(revPrefix.begin(), revPrefix.end());
                    if (wordSet.count(revPrefix) && revPrefix != word) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
  private:
    bool isPalindrome(const string& s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};
};

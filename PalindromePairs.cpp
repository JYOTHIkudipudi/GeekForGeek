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
  
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    bool palindromePair(vector<string>& arr) {
        
        unordered_set<string> st;
        
        // Store all strings
        for (auto &s : arr) {
            st.insert(s);
        }
        
        for (auto &s : arr) {
            
            int n = s.size();
            
            for (int i = 0; i <= n; i++) {
                
                string left = s.substr(0, i);
                string right = s.substr(i);
                
                // Case 1:
                // left is palindrome
                if (isPalindrome(left, 0, left.size() - 1)) {
                    
                    string revRight = right;
                    reverse(revRight.begin(), revRight.end());
                    
                    if (st.count(revRight) && revRight != s) {
                        return true;
                    }
                }
                
                // Case 2:
                // right is palindrome
                if (i != n && isPalindrome(right, 0, right.size() - 1)) {
                    
                    string revLeft = left;
                    reverse(revLeft.begin(), revLeft.end());
                    
                    if (st.count(revLeft) && revLeft != s) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};

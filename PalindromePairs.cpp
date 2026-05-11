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
    
    bool isPal(string &s) {
        int l = 0, r = s.size() - 1;
        
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        
        return true;
    }
    
    bool palindromePair(vector<string>& arr) {
        
        unordered_map<string, vector<int>> mp;
        
        // store all indices for duplicate handling
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
        
        for (int i = 0; i < arr.size(); i++) {
            
            string s = arr[i];
            int n = s.size();
            
            for (int j = 0; j <= n; j++) {
                
                string left = s.substr(0, j);
                string right = s.substr(j);
                
                // Case 1:
                // left palindrome
                if (isPal(left)) {
                    
                    string revRight = right;
                    reverse(revRight.begin(), revRight.end());
                    
                    if (mp.count(revRight)) {
                        
                        for (int idx : mp[revRight]) {
                            if (idx != i)
                                return true;
                        }
                    }
                }
                
                // Case 2:
                // right palindrome
                if (j != n && isPal(right)) {
                    
                    string revLeft = left;
                    reverse(revLeft.begin(), revLeft.end());
                    
                    if (mp.count(revLeft)) {
                        
                        for (int idx : mp[revLeft]) {
                            if (idx != i)
                                return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};
};

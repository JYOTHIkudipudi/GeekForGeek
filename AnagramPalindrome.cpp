/*  Anagram Palindrome
Given a string s, determine whether its characters can be rearranged to form a palindrome. Return true if it is possible to rearrange the string into a palindrome;
otherwise, return false.

Examples

Input: s = "baba"
Output: true
Explanation: Can be rearranged to form a palindrome "abba" 
Input: s = "geeksogeeks"
Output: true
Explanation: The characters of the string can be rearranged to form the palindrome "geeksoskeeg".
Input: s = "geeksforgeeks"
Output: false
Explanation: The given string can't be converted into a palindrome.
Constraints:
1 ≤ s.length ≤ 106
s consists of only lowercase English letters.   */

class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
    
        int freq[26] = {0};
        
        for(char c : s){
            freq[c - 'a']++;
        }
        
        int odd = 0;
        
        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 != 0)
                odd++;
        }
        
        return odd <= 1;
    }
};

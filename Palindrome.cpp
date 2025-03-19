/*  Palindrome
You are given an integer n. Your task is to determine whether it is a palindrome.
A number is considered a palindrome if it reads the same backward as forward, like the string examples "MADAM" or "MOM".

Examples:
Input: n = 555
Output: true
Explanation: The number 555 reads the same backward as forward, so it is a palindrome.
  
Input: n = 123
Output: false
Explanation: The number 123 reads differently backward (321), so it is not a palindrome.
  
Input: n = 1221
Output: true
  
Constraints:
1 <= n <= 109   */


 
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isPalindrome(int n) {
        int reverse = 0;
        int temp = abs(n);
        while(temp!=0){
            reverse = (reverse*10)+temp%10;
            temp /= 10;
        }
    return (reverse==abs(n));
    }
};
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        bool ans = ob.isPalindrome(n);
        cout << (ans ? "true" : "false") << "\n~\n";
    }
    return 0;
}

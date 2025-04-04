/*   Reverse digits

You are given an integer n. Your task is to reverse the digits, ensuring that the reversed number has no leading zeroes.

Examples:
Input: n = 122
Output: 221
Explanation: By reversing the digits of number, number will change into 221.
Input : n = 200
Output: 2
Explanation: By reversing the digits of number, number will change into 2.
Input : n = 12345 
Output: 54321
Explanation: By reversing the digits of number, number will change into 54321.
Constraints:
1 <= n <= 106     */

class Solution {
  public:
    int reverseDigits(int n) {
        int reverse=0;
        while(n>0){
        int lastdigit = n%10;
        reverse = reverse*10+lastdigit;
          n = n/10;
        }
        return reverse;
    }
};

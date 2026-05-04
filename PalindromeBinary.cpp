/*   Palindrome Binary

Given an integer n, determine whether its binary representation forms a palindrome.
Return true if the binary representation of n is a palindrome; otherwise, return false.

Note: A binary representation   is considered a palindrome if it reads the same forward and backward.

Examples:

Input: n = 17
Output: true
Explanation: Binary representation of 17 is (10001)2, which reads the same forward and backward, so it is a palindrome. 
Input: n = 16
Output: false
Explanation: Binary representation of 16 is (10000)2, which is not a palindrome. 
Constraints:
1 ≤ n ≤ 109  */

class Solution {
public:
    bool isBinaryPalindrome(int n) {
        int left = 31;  // assume 32-bit integer
        int right = 0;

        // find actual MSB (ignore leading zeros)
        while (((n >> left) & 1) == 0) {
            left--;
        }

        // compare bits
        while (left > right) {
            int lbit = (n >> left) & 1;
            int rbit = (n >> right) & 1;

            if (lbit != rbit) return false;

            left--;
            right++;
        }

        return true;
    }
};

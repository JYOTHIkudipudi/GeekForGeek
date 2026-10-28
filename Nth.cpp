/* Nth in Concatenated Decimal String

Consider a string s formed by concatenating the decimal representations of all positive integers in order:

s = "12345678910111213141516171819202122232425262728293031..."

Given an integer n, find the nth character (1-based indexing) in the string s.

Examples:

Input: n = 10
Output: '1'
Explanation: The 10th in "1234567891.." character is '1'.
Input: n = 11
Output: '0'
Explanation: The 11th character in "12345678910.."  is '0'.
Constraints:

1 ≤ n ≤ 109  */

class Solution {
public:
    char nthCharacter(int n) {
        long long count = 9;
        long long start = 1;
        int digits = 1;

        while (n > count * digits) {
            n -= count * digits;
            count *= 10;
            start *= 10;
            digits++;
        }

        long long number = start + (n - 1) / digits;
        int index = (n - 1) % digits;

        string s = to_string(number);
        return s[index];
    }
};


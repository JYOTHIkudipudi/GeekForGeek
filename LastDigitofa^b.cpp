/*   Last Digit of a^b
Given two integers a and b in the form of strings. Return the last digit of ab.

Examples:

Input: a = "3", b = "10"
Output: 9
Explanation: 310 = 59049. Last digit is 9.
Input: a = "6", b = "2"
Output: 6
Explanation: 62 = 36. Last digit is 6.
Constraints:
1 ≤ a.size(), b.size() ≤ 1000
a and b consist only of numeric digits ('0' - '9')
a and b do not contain any leading zeros, except when number itself is "0"  */4

  class Solution {
  public:
    int getLastDigit(string a, string b) {
        if (b == "0") return 1;

        int base = a.back() - '0';

        int rem = 0;
        for (char c : b)
            rem = (rem * 10 + (c - '0')) % 4;

        if (rem == 0) rem = 4;

        int ans = 1;
        while (rem--) {
            ans = (ans * base) % 10;
        }

        return ans;
    }
};

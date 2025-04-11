/* Sum Of Digits

Given a number n. Find the sum of all the digits of n.

Examples:
Input: n = 12
Output: 3
Explanation: Sum of 12's digits: 1 + 2 = 3
Input: n = 23
Output 5
Explanation: Sum of 23's digits: 2 + 3 = 5
Constraints:
1<= n <=105   */

class Solution {
  public:
    int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum; 
}
};

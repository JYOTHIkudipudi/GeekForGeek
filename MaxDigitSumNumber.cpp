/*  Max Digit Sum Number in 1 to n

Given a number n, find a number in the range from 1 to n such that its digit sum is maximum. If there are multiple such numbers, return the largest of them.

Examples:

Input: n = 48
Output: 48
Explanation: There are two numbers with maximum digit sum = 12. The numbers are 48 and 39. Since 48 > 39, so 48 is the answer.
Input: n = 90
Output: 89
Explanation: 89 gives us the largest digit sum in the range from 1 to n. Hence the answer is 89. 
Constraints:

1 ≤ n ≤ 109  */

class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        
        return sum;
    }

    int findMax(int n) {
        int ans = n;
        int maxSum = digitSum(n);

        int p = 1;

        while (p <= n) {
            // Decrease the digit at this position
            int candidate = (n / (p * 10)) * (p * 10) 
                          + ((n / p) % 10 - 1) * p 
                          + (p - 1);

            if (candidate >= 1) {
                int sum = digitSum(candidate);

                if (sum > maxSum || (sum == maxSum && candidate > ans)) {
                    maxSum = sum;
                    ans = candidate;
                }
            }

            p *= 10;
        }

        return ans;
    }
};


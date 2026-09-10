/* Pairs with Given GCD and LCM

Given two integers x and y representing the GCD and LCM of two unknown positive integers a and b, count the number of valid pairs (a, b) satisfying these conditions. 
Note that (a, b) and (b, a) are counted as distinct pairs when a ≠ b.

Examples:

Input: x = 2, y = 12
Output: 4
Explanation: The valid pairs are (2, 12), (4, 6), (6, 4), and (12, 2), since each pair has GCD = 2 and LCM = 12.
Input: x = 6, y = 4
Output: 0
Explanation: LCM must always be a multiple of GCD. Since y is not divisible by x, no valid pair exists.
Constraints:
1 ≤ x, y ≤ 104  */

class Solution {
public:
    int pairCount(int x, int y) {
        
        // LCM must be divisible by GCD
        if (y % x != 0)
            return 0;

        int n = y / x;
        int distinct = 0;

        // Count distinct prime factors of n
        for (int p = 2; p * p <= n; p++) {
            if (n % p == 0) {
                distinct++;

                // Remove all occurrences of p
                while (n % p == 0)
                    n /= p;
            }
        }

        // If remaining n > 1, it is also a prime factor
        if (n > 1)
            distinct++;

        // Number of ordered pairs = 2^distinct
        return 1 << distinct;
    }
};

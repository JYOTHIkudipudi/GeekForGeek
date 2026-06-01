/*  Max Product Subset

Given an array arr[], find and return the maximum product possible with the subset of elements present in the array.

Note:

The maximum product can be of a single element also.
Since the product can be large, return it modulo 109 + 7.
Examples:

Input: arr[] = [-1, 0, -2, 4, 3]
Output: 24
Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24
Input: arr[] = [-1, 0]
Output: 0
Explanation: Maximum product will be ( -1 * 0) = 0
Input: arr[] = [5]
Output: 5
Explanation: Maximum product will be 5.
Constraints:
1 ≤ arr.size() ≤ 2 * 104   */

class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        long long mod = 1000000007;

        int neg = 0, zero = 0;
        int mxNeg = -11;
        long long prod = 1;

        for (int x : arr) {
            if (x == 0) {
                zero++;
                continue;
            }

            if (x < 0) {
                neg++;
                mxNeg = max(mxNeg, x);
            }

            prod = (prod * x) % mod;
        }

        if (zero == arr.size())
            return 0;

        if (neg == 1 && neg + zero == arr.size()) {
            if (zero > 0) return 0;
            return arr[0];
        }

        if (neg & 1) {
            // divide by mxNeg using modular inverse
            long long p = mod - 2;
            long long inv = 1;
            long long base = (mxNeg % mod + mod) % mod;

            while (p) {
                if (p & 1) inv = (inv * base) % mod;
                base = (base * base) % mod;
                p >>= 1;
            }

            prod = (prod * inv) % mod;
        }

        return (prod + mod) % mod;
    }
};

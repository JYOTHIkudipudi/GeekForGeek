/*  Subsets with MEX in Range

Given an array arr[] of integers and a range [l, r], count the number of subsets whose Minimum Excluded (MEX) value lies within the given range, inclusive.

Minimum Excluded (or MEX) of a subset is the smallest non-negative integer that is not present in the subset.
An empty subset has Minimum Excluded as zero.
Since the answer can be very large, return the answer modulo 109 + 7.

Examples:

Input: arr[] = [2, 0, 1, 0], l = 1, r = 2
Output: 9
Explanation: The subsets whose MEX lies in the range [1, 2] are counted as follows:
MEX = 1: The subsets must contain at least one 0 and must not contain 1. These subsets are [0] (2 ways), [2, 0] (2 ways), [0, 0] (1 way), and [2, 0, 0] (1 way). Total = 6.
MEX = 2: The subsets must contain both 0 and 1 but must not contain 2. These subsets are [0, 1] (2 ways) and [0, 1, 0] (1 way). Total = 3.
The subsets [2, 0, 1] and [2, 0, 1, 0] have MEX = 3, which is outside the given range. Therefore, the total number of valid subsets is 6 + 3 = 9.
Input: arr[] = [2, 0, 1], l = 1, r = 2
Output: 3
Explanation: The subsets whose MEX lies in the range [1, 2] are [0] (MEX = 1), [2, 0] (MEX = 1), and [0, 1] (MEX = 2). Hence, the answer is 3.
Constraints:

2 ≤ arr.size() ≤ 105
0 ≤ arr[i], r ≤ arr.size()
0 ≤ l ≤ r  */

```cpp
class Solution {
public:
    int cntSubsets(vector<int>& arr, int l, int r) {
        const long long MOD = 1000000007LL;
        int n = arr.size();

        vector<int> freq(n + 1, 0);
        for (int x : arr) {
            if (x <= n)
                freq[x]++;
        }

        vector<long long> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow2[i] = (pow2[i - 1] * 2) % MOD;

        long long requiredWays = 1;
        long long ans = 0;
        int requiredCount = 0;

        for (int mex = 0; mex <= r; mex++) {
            if (mex > 0) {
                int x = mex - 1;

                if (freq[x] == 0)
                    requiredWays = 0;
                else
                    requiredWays = requiredWays *
                        (pow2[freq[x]] - 1 + MOD) % MOD;

                requiredCount += freq[x];
            }

            if (mex >= l) {
                int optionalCount = n - requiredCount - freq[mex];

                long long ways =
                    requiredWays * pow2[optionalCount] % MOD;

                ans = (ans + ways) % MOD;
            }
        }

        return static_cast<int>(ans);
    }
};
```

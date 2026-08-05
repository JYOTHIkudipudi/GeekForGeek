/*   Subarrays with Sum in Range

Given an integer array arr[] and two integers l and r, find the number of subarrays whose sum lies in the range [l, r] (inclusive).

A subarray is a contiguous sequence of elements within the array.

Examples:

Input: l = 3, r = 8, arr[] = [1, 4, 6]
Output: 3
Explanation: The subarrays are [1,4], [4] and [6]. Therefore answer for this test case is 3.
Input: l = 4, r = 13, arr[] = [2, 3, 5, 8]
Output: 6
Explanation: The subarrays are [2, 3], [2, 3, 5], [3, 5], [5], [5, 8] and [8]. 
Therefore answer for this test case is 6.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
1 ≤ l ≤ r ≤ 109  */

class Solution {
  public:
    long long countAtMost(vector<int>& arr, long long x) {
        if (x < 0) return 0;

        long long ans = 0, sum = 0;
        int left = 0;

        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right];

            while (sum > x) {
                sum -= arr[left++];
            }

            ans += (right - left + 1);
        }

        return ans;
    }

    int countSubarray(vector<int>& arr, int l, int r) {
        return (int)(countAtMost(arr, r) - countAtMost(arr, (long long)l - 1));
    }
};

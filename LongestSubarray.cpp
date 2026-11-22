/*  Longest Subarray Sum Divisible by K

Given an array arr[] and a positive integer k, find the length of the longest subarray whose sum is divisible by k.

Note: If there is no subarray with sum divisible by k, then return 0.

Examples:

Input: arr[] = [2, 7, 6, 1, 4, 5], k = 3
Output: 4
Explanation: The subarray [7, 6, 1, 4] has sum = 18, which is divisible by 3.
Input: arr[] = [-2, 2, -5, 12, -11, -1, 7], k = 3
Output: 5
Explanation: The subarray [2, -5, 12, -11, -1] has sum = -3, which is divisible by 3.
Input: arr[] = [1, 2, -2], k = 2
Output: 2
Explanation: The subarray is [2, -2] has sum = 0, which is divisible by 2.
Constraints:

1 ≤ arr.size(), k ≤ 105
-105 ≤ arr[i] ≤ 105
*/


class Solution {
public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        int prefixSum = 0;
        int maxLen = 0;

        // Remainder 0 before the array starts
        mp[0] = -1;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            // Handle negative numbers
            int rem = ((prefixSum % k) + k) % k;

            if (mp.find(rem) != mp.end()) {
                maxLen = max(maxLen, i - mp[rem]);
            }
            else {
                mp[rem] = i;
            }
        }

        return maxLen;
    }
};

/*  Smallest Subarray Sum Greater Than x

Given an integer x and an array of integers, arr[]. Find the length of the smallest subarray whose sum is strictly greater than x.

If no such subarray exists, return 0.

Examples:

Input: x = 51, arr[] = [1, 4, 45, 6, 0, 19]
Output: 3
Explanation: The smallest subarray with a sum greater than 51 is [4, 45, 6], whose sum is 55 and length is 3.
Input: x = 100, arr[] = [1, 10, 5, 2, 7]
Output: 0
Explanation: No subarray has a sum greater than 100. Hence, the answer is 0.
Constraints:

1 ≤ x, arr.size() ≤ 105
0 ≤ arr[i] ≤ 104  */


class Solution {
public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        int n = arr.size();

        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > x) {
                ans = min(ans, right - left + 1);
                sum -= arr[left];
                left++;
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};

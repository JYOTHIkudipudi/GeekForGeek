/*   Max Absolute Diff of Two Subarrays

Given an array of integers arr[], find two non-overlapping contiguous sub-arrays such that the absolute difference between the sum of two sub-arrays is maximum.

Examples :

Input: arr[] = [-2, -3, 4, -1, -2, 1, 5, -3]
Output: 12
Explanation: Two subarrays are [-2, -3] and [4, -1, -2, 1, 5]
Input: arr[] = [2, -1, -2, 1, -4, 2, 8]
Output: 16
Explanation: Two subarrays are [-1, -2, 1, -4] and [2, 8] 
Constraints:
2 ≤ arr.size() ≤ 105
-103 ≤ arr[i] ≤ 103   */

class Solution {
public:
    int maxDiffSubArrays(vector<int>& arr) {
        int n = arr.size();

        vector<int> leftMax(n), leftMin(n), rightMax(n), rightMin(n);

        // Maximum subarray from left
        int currMax = arr[0];
        leftMax[0] = arr[0];
        for (int i = 1; i < n; i++) {
            currMax = max(arr[i], currMax + arr[i]);
            leftMax[i] = max(leftMax[i - 1], currMax);
        }

        // Minimum subarray from left
        int currMin = arr[0];
        leftMin[0] = arr[0];
        for (int i = 1; i < n; i++) {
            currMin = min(arr[i], currMin + arr[i]);
            leftMin[i] = min(leftMin[i - 1], currMin);
        }

        // Maximum subarray from right
        currMax = arr[n - 1];
        rightMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            currMax = max(arr[i], arr[i] + currMax);
            rightMax[i] = max(rightMax[i + 1], currMax);
        }

        // Minimum subarray from right
        currMin = arr[n - 1];
        rightMin[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            currMin = min(arr[i], arr[i] + currMin);
            rightMin[i] = min(rightMin[i + 1], currMin);
        }

        int ans = 0;

        // Try every possible split
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, abs(leftMax[i] - rightMin[i + 1]));
            ans = max(ans, abs(leftMin[i] - rightMax[i + 1]));
        }

        return ans;
    }
};

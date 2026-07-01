/*   Max Subarray Sum by Removing At Most One

Given an array arr[], find the maximum sum of a non-empty subarray. You are allowed to skip at most one element in the subarray.

Note: After skipping the element, the subarray must still be non-empty.

Examples:

Input: arr[] = [1, 2, 3, -4, 5]
Output: 11
Explanation: We can get maximum sum subarray by skipping -4.
Input: arr[] = [-2, -3, 4, -1, -2, 1, 5, -3]
Output: 9
Explanation: We can get maximum sum subarray by skipping -2 as [4,-1,1,5] sums to 9, which is the maximum achievable sum.
Constraints:
1 ≤ arr.size() ≤ 106
-103 ≤ arr[i] ≤ 103  */



class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();

        int keep = arr[0];      // Max sum ending here without deletion
        int drop = INT_MIN;     // Max sum ending here with one deletion
        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            int prevKeep = keep;

            // No deletion
            keep = max(arr[i], keep + arr[i]);

            // One deletion
            if (drop == INT_MIN)
                drop = prevKeep;                // Delete current element
            else
                drop = max(drop + arr[i], prevKeep);

            ans = max(ans, max(keep, drop));
        }

        return ans;
    }
};


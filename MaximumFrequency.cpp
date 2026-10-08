/*  Maximum Frequency with K Increments
Given an integer array arr[]. In one operation, you can choose an index and increment its value by 1.

Find the maximum possible frequency of any element after performing at most k operations.

Examples:

Input: arr[] = [2, 2, 4], k = 4
Output: 3
Explanation: Apply two increment operations on index 0 and two operations on index 1 to make arr[]= [4, 4, 4]. Frequency of 4 is 3.
Input: arr[] = [7, 7, 7, 7], k = 5
Output: 4
Explanation: The frequency of 7 is already 4, so no operations are needed.

Constraints:

1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106
0 ≤ k ≤ 105
*/

class Solution {
  public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        long long windowSum = 0;
        int l = 0, best = 1;

        for (int r = 0; r < (int)arr.size(); r++) {
            windowSum += arr[r];

            // cost to make all elements in [l, r] equal to arr[r]
            while ((long long)arr[r] * (r - l + 1) - windowSum > k) {
                windowSum -= arr[l];
                l++;
            }

            best = max(best, r - l + 1);
        }
        return best;
    }
};

/*  Mountain Subarray Queries

Given an array arr[] and a list of queries. For each query [l, r], find whether the subarray arr[l...r] is a mountain array. 
A subarray is called a mountain array if there exists an index k (l ≤ k ≤ r) such that: arr[l] ≤ arr[l + 1] ≤ ... ≤ arr[k] ≥ arr[k + 1] ≥ ... ≥ arr[r].

Elements of a Mountain subarray are first non-decreasing and then non-increasing.
A subarray that is entirely non-decreasing or entirely non-increasing is also considered a mountain.
Examples:

Input: arr[] = [2, 3, 2, 4, 4, 6, 3, 2], queries[][] = [[0, 2], [1, 3]]
Output: [true, false]
Explanation: For query [0, 2], the subarray is [2, 3, 2]. The elements first increase and then decrease, so it forms a mountain.
For query [1, 3], the subarray is [3, 2, 4]. The elements decrease and then increase, so it does not form a mountain.
Input: arr[] = [2, 2, 2, 2], queries[][] = [[0, 2], [1, 3]]
Output: [true, true]
Explanation: All subarrays of the given array are mountain.
Constraints:
1 <= arr.size(), queries.size() <= 105
1 <= arr[i] <= 106
0 <= l <= r < arr.size()  */

class Solution {
public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {

        int n = arr.size();

        vector<int> inc(n), dec(n);

        // farthest non-decreasing end
        inc[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1])
                inc[i] = inc[i + 1];
            else
                inc[i] = i;
        }

        // leftmost start of non-increasing segment
        dec[0] = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] >= arr[i])
                dec[i] = dec[i - 1];
            else
                dec[i] = i;
        }

        vector<bool> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            ans.push_back(dec[r] <= inc[l]);
        }

        return ans;
    }
};

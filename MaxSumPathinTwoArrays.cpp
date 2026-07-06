/* Max Sum Path in Two Arrays
Given two sorted arrays of distinct integers in increasing order a[] and b[], which may have some common elements, find the maximum sum of a path from the beginning of any array to the end of any array. You may switch from one array to the other only at common elements.

Note:  When switching, count the common element only once.

Examples : 

Input: a[] = [2, 3, 7, 10, 12], b[] = [1, 5, 7, 8]
Output: 35
Explanation: The path will be (1 + 5 + 7 + 10 + 12) = 35, where 1 and 5 come from arr2 and then 7 is common so we switch to arr1 and add 10 and 12.
Input: a[] = [1, 2, 3], b[] = [3, 4, 5]
Output: 15
Explanation: The path will be (1 + 2 + 3 + 4 + 5) = 15.
Constraints:
1 ≤ a.size(), b.size() ≤ 104
1 ≤ a[i], b[i] ≤ 105  */

class Solution {
public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        long long sum1 = 0, sum2 = 0, ans = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                sum1 += a[i];
                i++;
            } 
            else if (a[i] > b[j]) {
                sum2 += b[j];
                j++;
            } 
            else {
                // Common element: choose the better path so far
                ans += max(sum1, sum2) + a[i];
                sum1 = sum2 = 0;
                i++;
                j++;
            }
        }

        // Add remaining elements
        while (i < a.size()) {
            sum1 += a[i++];
        }

        while (j < b.size()) {
            sum2 += b[j++];
        }

        ans += max(sum1, sum2);

        return ans;
    }
};

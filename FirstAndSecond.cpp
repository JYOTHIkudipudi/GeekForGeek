/*    First and Second Smallests

Given an array, arr of integers, your task is to return the smallest and second smallest element in the array. 
If the smallest and second smallest do not exist, return -1.

Examples:
Input: arr[] = [2, 4, 3, 5, 6]
Output: 2 3 
Explanation: 2 and 3 are respectively the smallest and second smallest elements in the array.
Input: arr[] = [1, 1, 1]
Output: -1
Explanation: Only element is 1 which is smallest, so there is no second smallest element.
Expected Time Complexity: O(n)
Expected Auxillary Space: O(1)

Constraints:
1 <= arr.size <= 105
1 <= arr[i] <= 105    */


class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        int n = arr.size();
    int first = INT_MAX, second = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > first && arr[i] < second) {
            second = arr[i];
        }
    }

    if (second == INT_MAX) {
        return {-1, -1};
    }
    return {first, second};
}
};

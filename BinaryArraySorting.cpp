/*   Binary Array Sorting

You are given a binary array arr[], where each element is either 0 or 1.
  Your task is to rearrange the array in increasing order in place (without using extra space). 
  You do not need to return anything; simply modify the input array.

Examples:
Input: arr[] = [1, 0, 1, 1, 0]
Output: [0, 0, 1, 1, 1]
Explanation: After arranging the elements in increasing order, elements will be as 0 0 1 1 1.
Input: arr[] = [1, 0, 1, 1, 1, 1, 1, 0, 0, 0]
Output: [0, 0, 0, 0, 1, 1, 1, 1, 1, 1]
Explanation: After arranging the elements in increasing order, elements will be 0 0 0 0 1 1 1 1 1 1.
Input: arr[] = [1, 1, 1, 1]
Output: [1, 1, 1, 1]
Explanation: Since the array already contains only 1s, no change is needed.

Constraints:
1 ≤ arr.size() ≤ 106
arr[i] ∈ {0,1} for all valid indices i.  */


class Solution {
  public:
    void binSort(vector<int> &arr) {
        // code here 
         int count0 = 0;

    // Count number of 0s
    for (int num : arr) {
        if (num == 0) count0++;
    }

    // Fill with 0s
    for (int i = 0; i < count0; i++) {
        arr[i] = 0;
    }

    // Fill the rest with 1s
    for (int i = count0; i < arr.size(); i++) {
        arr[i] = 1;
    }
    }
};

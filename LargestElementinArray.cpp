/*  Largest Element in Array

Given an array arr[]. The task is to find the largest element and return it.

Examples:
Input: arr[] = [1, 8, 7, 56, 90]
Output: 90
Explanation: The largest element of the given array is 90.
Input: arr[] = [5, 5, 5, 5]
Output: 5
Explanation: The largest element of the given array is 5.
Input: arr[] = [10]
Output: 10
Explanation: There is only one element which is the largest.
Constraints:
1 <= arr.size()<= 106
0 <= arr[i] <= 106   */

// code 
class Solution {
  public:
    int largest(vector<int> &arr) {
      int maxVal = INT_MIN ;
      for(int i=0;i<arr.size();i++){
          if(maxVal < arr[i])  {
              maxVal = arr[i];
          }
      }
      return maxVal;
    }
};

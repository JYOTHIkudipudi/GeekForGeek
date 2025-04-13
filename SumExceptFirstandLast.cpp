/*  Sum Except First and Last
You are given an array arr of numbers. Return the sum of all the elements except the first and last elements.

Examples:
Input: arr[] = [5, 24, 39, 60, 15, 28, 27, 40, 50, 90]
Output: 283
Explanation: The sum of all the elements except the first and last element is 283.
Input: arr[] = [5, 10, 1, 11]
Output: 11
Explanation: The sum of all the elements except the first and last element is 11.
Input: arr[] = [5, 10]
Output: 0
Explanation: The sum of all the elements except the first and last element is 0.

Constraints:
2<=arr.size()<=105
2<=arr[i]<=105   */

class Solution {
  public:
    int sumExceptFirstLast(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for(int i=1;i<n-1;i++){
            sum += arr[i];
        }
        return sum;
    }
};

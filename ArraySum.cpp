/*   Sum of Array
You are given an integer array arr[]. The task is to find the sum of it.

Examples:
Input: arr[] = [1, 2, 3, 4]
Output: 10
Explanation: 1 + 2 + 3 + 4 = 10.
Input: arr[] = [1, 3, 3]
Output: 7
Explanation: 1 + 3 + 3 = 7.
  
Constraints:
1 <= arr.size <= 105
1 <= arr[i] <= 104   */

class Solution {
  public:
    // Function to return sum of elements
    int arraySum(vector<int>& arr) {
        // code here
           int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
    }
};


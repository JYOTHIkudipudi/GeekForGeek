/*    Rotate Array by One

Given an array arr, rotate the array by one position in clockwise direction.

Examples:
Input: arr[] = [1, 2, 3, 4, 5]
Output: [5, 1, 2, 3, 4]
Explanation: If we rotate arr by one position in clockwise 5 come to the front and remaining those are shifted to the end.
Input: arr[] = [9, 8, 7, 6, 4, 2, 1, 3]
Output: [3, 9, 8, 7, 6, 4, 2, 1]
Explanation: After rotating clock-wise 3 comes in first position.

Constraints:
1<=arr.size()<=105
0<=arr[i]<=105  */

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int n = arr.size();
    int last = arr[n - 1];  // Step 1: Save last element

    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];  // Step 2: Shift elements right
    }

    arr[0] = last;  // Step 3: Put last at the front
}

// Helper function to print array
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

};

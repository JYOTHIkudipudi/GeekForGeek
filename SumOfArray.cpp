/*    Sum of Array

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
1 <= arr[i] <= 104    */

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int arraySum(vector<int>& arr) {
        // code here
        int sum =0;
        for(int i=0;i<=arr.size()-1;i++){
            sum += arr[i];
        }
        return sum;
    }
};
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        int ans = ob.arraySum(nums); // Pass the vector nums to the sum function
        cout << ans << "\n~\n";
    }
    return 0;
}





/*  Sort The Array

Given a random array arr of numbers, please return them in ascending sorted order. 
Note: Use Inbuilt functions to Sort the given array

Examples:
Input: arr[] = [1, 5, 3, 2]
Output: [1, 2, 3, 5]
Explanation: After sorting array will be like [1, 2, 3, 5].
Input: arr[] = [3, 1]
Output: [1, 3]
Explanation: After sorting array will be like [1, 3].
Input: arr[] = [1, 2, 3]
Output: [1, 2, 3]
Explanation: It's already in expected form.      */



#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sortArr(vector<int> &arr) {
        sort(arr.begin(),arr.end());
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
        ob.sortArr(nums);
        for (auto i : nums)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

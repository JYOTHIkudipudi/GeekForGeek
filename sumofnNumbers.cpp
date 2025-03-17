/*  Sum of Natural Numbers   https://www.geeksforgeeks.org/problems/sum-of-series2811/1?page=1&difficulty=Basic&sortBy=submissions

Given an integer n, your task is to compute the sum of all natural numbers from 1 to n (inclusive). If n is 0, the sum should be 0.

Examples:
Input: n = 1
Output: 1
Explanation: For n = 1, the sum will be 1.
  
Input: n = 5
Output: 15
Explanation: For n = 5, sum will be 15. 1 + 2 + 3 + 4 + 5 = 15.
  
Constraints: 
1 <= n <= 104     */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int seriesSum(int n) {
        // code here
         int sum = n*(n+1)/2;
         return sum;
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.seriesSum(n);

        cout << res << endl;
        cout << "~" << endl;
    }
}

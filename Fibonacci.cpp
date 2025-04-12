/* 
First n Fibonacci
Given a number n, return an array containing the first n Fibonacci numbers.

Note: The first two numbers of the series are 0 and 1.

Examples:
Input: n = 5
Output: [0, 1, 1, 2, 3]
Input: n = 7
Output: [0, 1, 1, 2, 3, 5, 8]
Input: n = 2
Output: [0, 1]

Constraints:
1 <= n <= 30   */

class Solution {
  public:
    // Function to return list containing first n fibonacci numbers.
    vector<int> fibonacciNumbers(int n) {
        // code here
        int first=0,second=1;
        for(int i=1;i<=n;i++){
            cout << first << " " ;
            int next = first + second;
            first = second;
            second = next;
        }
    }
};

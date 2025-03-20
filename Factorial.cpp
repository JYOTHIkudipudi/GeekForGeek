 / *   FACTORIAL
Given a positive integer, n. Find the factorial of n.

Examples :
Input: n = 5
Output: 120
Explanation: 1 x 2 x 3 x 4 x 5 = 120
Input: n = 4
Output: 24
Explanation: 1 x 2 x 3 x 4 = 24
Constraints:
0 <= n <= 12       */  


#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
        // code here
        long long factorial(int n) {
        long long fact = 1;
        for(int i = 2; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.factorial(N) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}



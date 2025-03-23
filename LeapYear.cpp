/*   Leap Year

You are given an Integer n. Return true if It is a Leap Year otherwise return false.

Examples:
Input: n = 4
Output: true
Explanation: 4 is not divisible by 100 and is divisible by 4 so its a leap year
Input: n = 2021
Output: false
Explanation: 2021 is not divisible by 100 and is also not divisible by 4 so its not a leap year
Constraints:
1<= n < 104    */


#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool checkYear(int n) {
        if((n%4==0 && n%100!=0) || (n%400==0)){
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;

        if (ob.checkYear(N))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

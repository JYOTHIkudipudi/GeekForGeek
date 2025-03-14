/*     https://www.geeksforgeeks.org/problems/lcm--151453/1
  LCM
Given two numbers a and b. The task is to find out their LCM.

Examples:
Input: a = 5, b = 10
Output: 10
Explanation: LCM of 5 and 10 is 10
Input: a = 14, b = 8
Output: 56
Explanation: LCM of 14 and 8 is 56   */


#include <iostream>
using namespace std;
int gcd(int a,int b){
    return(b==0) ? a: gcd(b,a%b);
}
int lcm(int a,int b){
    return(a/gcd(a,b))*b;
}
int main() {
    // code here
    int a,b;
    cin >> a >> b;
    cout << lcm(a,b) << endl;
    
    return 0;
}

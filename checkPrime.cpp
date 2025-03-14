/*   Check Prime
https://www.geeksforgeeks.org/problems/check-prime--153305/1
Given an integer n check if n is prime or not.
A prime number is a number that is divisible by 1 and itself only.

Note: Print "True" if n is prime, otherwise print "False".

Examples:

Input: n = 17
Output: True 
Explanation: 17 is  divisible by only 1 and 17. So it's a prime number.
Input: n = 56
Output: False
Explanation: 56 is divisible by 2, 4, 7.....etc. So its not a prime number.
Contraints:
1 <= n <= 104    */

#include <bits/stdc++.h>
using namespace std;
bool isprime(int n){
    if(n<2) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
    }
    return true;
}
int main() {
    // code here
    int n;
    cin >> n;
    if(isprime(n)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}

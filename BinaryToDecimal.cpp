/*   Binary to Decimal
https://www.geeksforgeeks.org/problems/binary-to-decimal-1611122504--161115/1

Given a Binary Number n, find its decimal equivalent.
Examples :
Input: n = 10001000
Output: 136
Input: n = 101100
Output: 44   */

#include<bits/stdc++.h>
using namespace std;
int main(){
   string n;
   cin >> n;
   cout << stoi(n,0,2) << endl;
return 0;
}

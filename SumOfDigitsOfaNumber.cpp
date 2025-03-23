/*   Sum of Digits of a Number
https://www.geeksforgeeks.org/problems/sum-of-digits-of-a-number/1?page=5&difficulty=Basic&sortBy=submissions
You are given a number n. You need to find the sum of digits of n.

Example 1:

Input:
n = 1
Output: 1
Explanation: Sum of digit of 1 is 1.
Example 2:

Input:
n = 99999
Output: 45
Explanation: Sum of digit of 99999 is 45.
Your Task:
You don't need to read input or print anything. Your task is to complete the function sumOfDigits() that takes n as parameter and returns the sum of digits of n.

Expected Time Complexity: O(Logn).
Expected Auxiliary Space: O(Logn) (Recursive).

Constraints:
1 <= n <= 107   */


#include <iostream>
using namespace std;
class Solution{
  public:
    int sumOfDigits(int n)
    {
        int sum = 0;
         n = abs(n);
         while(n>0){
             sum += n%10;
             n /= 10;
         }
         return sum;
        
    }
};

int main() {
	int T;
	
	//taking testcases
	cin>>T;
	while(T--)
	{
	    int n;
	    
	    //taking input n
	    cin>>n;
	    
	    //calling method sumOfDigits()
	    Solution obj;
	    cout<<obj.sumOfDigits(n)<<endl;
	    
	    
	
cout << "~" << "\n";
}
	return 0;
}

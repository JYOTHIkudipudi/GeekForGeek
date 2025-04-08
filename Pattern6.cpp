/*    Pattern 6
Difficulty: BasicAccuracy: 65.67%Submissions: 50K+Points: 1Average Time: 10m
Geek is very fond of patterns. Once, his teacher gave him a  pattern to solve. He gave Geek an integer n and asked him to build a pattern.
Help Geek to build a pattern.
Example 1:
Input: 5
Output:
1 2 3 4 5
1 2 3 4
1 2 3 
1 2  
1 

Your Task:
You don't need to input anything. Complete the function printTriangle() which takes  an integer n  as the input parameter and print the pattern.

Constraints:
1<= N <= 20    */

class Solution{
public:
	
	void printTriangle(int n) {
	    // code here
	    for(int i=n;i>=1;i--){
	        for(int j=1;j<=i;j++){
	            cout <<j <<" ";
	        }
	        cout << endl;
	    }
	}
}

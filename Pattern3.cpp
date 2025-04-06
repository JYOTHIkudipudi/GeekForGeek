/*   Pattern 3
Geek is very fond of patterns. Once, his teacher gave him a  pattern to solve. He gave Geek an integer n and asked him to build a pattern.
Help Geek to build a pattern. 

Example 1:
Input: 5
Output:
1
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5
Example 2:

Input: 3
Output:
1
1 2 
1 2 3 
Your Task:

You don't need to input anything. Complete the function printTriangle() which takes an integer n  as the input parameter and prints the pattern.

Expected Time Complexity: O(n2).
Expected Auxiliary Space: O(1).

Constraints:
1<= n <= 100    */


class Solution {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

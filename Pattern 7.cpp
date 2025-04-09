/*   Pattern 7

Geek is very fond of patterns. Once, his teacher gave him a pattern to solve. He gave Ram an integer n and asked him to build a pattern.
Help Ram build a pattern.

Example 1:
Input: 5
Output:
    *
   ***  
  *****
 *******
*********
Example 2:

Input: 3
Output:
  *
 ***  
*****
Your Task:
You don't need to input anything. Complete the function printTriangle() which takes an integer n  as the input parameter and prints the pattern.

Expected Time Complexity: O(n2).
Expected Auxiliary Space: O(1)

Constraints:
1<= n <= 1000  */



class Solution {
  public:
    void printTriangle(int n) {
        // code here
       for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        // New line
        cout << endl;
    }
    }
};

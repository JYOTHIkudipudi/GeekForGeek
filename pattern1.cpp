/* Pattern 1
Geek is very fond of patterns. Once, his teacher gave him a square pattern to solve. He gave Geek an integer n and asked him to build a pattern.
Help Geek to build a square pattern with the help of *  such that each * is space-separated in each line.
Example 1:

Input:
n = 3
Output:
* * *
* * *
* * *
Example 2:

Input:
n = 5
Output:
* * * * *
* * * * *
* * * * *
* * * * *
* * * * *
Your Task: You don't need to input anything. Complete the function printSquare() which takes  an integer n  as the input parameter and print the pattern.  */

class Solution {
  public:
    void printSquare(int n) {
        // code here
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout << "*" <<" ";
            }
            cout << endl;
        }
    }
};






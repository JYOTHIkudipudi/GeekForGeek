/*   Middle of Three

Given three distinct numbers a, b and c. Find the number with a value in the middle (Try to do it with minimum comparisons).

Examples :
  
Input: a = 978, b = 518, c = 300
Output: 518
Explanation: Since 518>300 and 518<978, so 518 is the middle element.
  
Input: a = 162, b = 934, c = 200
Output: 200
Exaplanation: Since 200>162 && 200<934, So, 200 is the middle element.
  
Input: a = 246, b = 214, c = 450
Output: 246
  
Constraints:
1<=a, b, c<=109
a, b, c are distinct.   */


class Solution {
  public:
    int middle(int a, int b, int c) {
          if ((a > b && a < c) || (a < b && a > c))
        return a;
    else if ((b > a && b < c) || (b < a && b > c))
        return b;
    else
        return c;
    }
};



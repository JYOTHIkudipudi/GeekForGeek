/*  Non-Attacking Black and White Knights

Given two integers n and m representing the dimensions of a chessboard, 
find the number of ways to place one black knight and one white knight on the chessboard such that they cannot attack each other.

Note:

The knights have to be placed on different squares.
A knight can move two squares horizontally and one square vertically (L shaped), or two squares vertically and one square horizontally (L shaped).
The knights attack each other if one can reach the other in one move.
Examples:

Input: n = 2, m = 2
Output: 12 
Explanation: There are 12 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.
Input: n = 2, m = 3
Output: 26
Explanation: There are 26 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.
Constraints:
1 ≤ n ≤ 200
1 ≤ m ≤ 225  */

class Solution {
public:
    int numOfWays(int n, int m) {
        long long cells = 1LL * n * m;
        
        long long total = cells * (cells - 1);
        
        long long attacking = 0;
        
        if (n >= 2 && m >= 3)
            attacking += 4LL * (n - 1) * (m - 2);
            
        if (n >= 3 && m >= 2)
            attacking += 4LL * (n - 2) * (m - 1);
        
        return (int)(total - attacking);
    }
};

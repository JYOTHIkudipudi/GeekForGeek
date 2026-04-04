/*  Gray Code

Given a number n, generate bit patterns from 0 to 2n-1 such that successive patterns differ by one bit. 
A Gray code sequence must begin with 0.
 
Examples:
Input: n = 2
Output: ["00", "01", "11", "10"]
Explanation: 
00 and 01 differ by one bit.
01 and 11 differ by one bit.
11 and 10 also differ by one bit.
Input: n = 3
Output: ["000", "001", "011", "010", "110", "111", "101", "100"]
Explanation:
000 and 001 differ by one bit.
001 and 011 differ by one bit.
011 and 010 differ by one bit.
Similarly, every successive pattern 
differs by one bit.
Constraints :
1 ≤ n ≤ 16   */

class Solution {
  public:
    vector<string> graycode(int n) {
        // code here
        vector<string> result;
        
        int total = 1 << n; // 2^n
        
        for(int i = 0; i < total; i++) {
            int gray = i ^ (i >> 1);
            
            // convert to binary string of length n
            string bin = "";
            for(int j = n - 1; j >= 0; j--) {
                if(gray & (1 << j)) bin += '1';
                else bin += '0';
            }
            
            result.push_back(bin);
        }
        return result;
    }
};

/*   Next Smallest Palindrome

Given a number, in the form of an array num[] containing digits from 1 to 9(inclusive). Find the next smallest palindrome strictly larger than the given number.

Examples:

Input: num[] = [9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2]
Output: [9, 4, 1, 8, 8, 0, 8, 8, 1, 4, 9]
Explanation: Next smallest palindrome is 9 4 1 8 8 0 8 8 1 4 9.
Input: num[] = [2, 3, 5, 4, 5]
Output: [2, 3, 6, 3, 2]
Explanation: Next smallest palindrome is 2 3 6 3 2.
Constraints:
1 ≤ n ≤ 105
1 ≤ num[i] ≤ 9  */

class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        
        int n = num.size();
        
        // Check if all digits are 9
        bool all9 = true;
        for(int i = 0; i < n; i++){
            if(num[i] != 9){
                all9 = false;
                break;
            }
        }
        
        if(all9){
            vector<int> res(n+1,0);
            res[0] = 1;
            res[n] = 1;
            return res;
        }
        
        vector<int> ans = num;

        // Mirror left to right
        for(int i = 0; i < n/2; i++){
            ans[n-1-i] = ans[i];
        }

        // Check if mirrored > original
        bool greater = false;
        for(int i = 0; i < n; i++){
            if(ans[i] > num[i]){
                greater = true;
                break;
            }
            if(ans[i] < num[i]){
                break;
            }
        }

        if(greater) return ans;

        // Increase middle
        int carry = 1;
        int mid = (n-1)/2;

        while(mid >= 0 && carry){
            ans[mid] += carry;
            carry = ans[mid] / 10;
            ans[mid] %= 10;
            mid--;
        }

        // Mirror again
        for(int i = 0; i < n/2; i++){
            ans[n-1-i] = ans[i];
        }

        return ans;
    }
};

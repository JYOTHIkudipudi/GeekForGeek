/*  N-Digit Numbers with Increasing Digits
Difficulty: MediumAccuracy: 49.66%Submissions: 24K+Points: 4
Given an integer n, return all the n digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).

Examples :

Input: n = 1
Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
Explanation: Single digit numbers are considered to be strictly increasing order.
Input: n = 2
Output: [12, 13, 14, 15, 16, 17, 18, 19, 23....79, 89]
Explanation: For n = 2, the correct sequence is 12 13 14 15 16 17 18 19 23 and so on up to 89.
Input: n = 15
Output: []
Explanation: No such number exist. 
Constraints:
1 ≤ n ≤ 105  */
class Solution {
public:
    vector<int> increasingNumbers(int n) {
        vector<int> ans;

        if (n > 10) return ans;

        if (n == 1) {
            for (int i = 0; i <= 9; i++) ans.push_back(i);
            return ans;
        }

        function<void(int, int, int)> dfs = [&](int len, int start, int num) {
            if (len == n) {
                ans.push_back(num);
                return;
            }

            for (int d = start; d <= 9; d++) {
                dfs(len + 1, d + 1, num * 10 + d);
            }
        };

        for (int first = 1; first <= 9; first++) {
            dfs(1, first + 1, first);
        }

        return ans;
    }
};

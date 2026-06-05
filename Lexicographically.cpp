/*  Lexicographically smallest after removing k

Given a string s consisting of n lowercase characters. Return the lexicographically smallest string after removing exactly 
k characters from the string. But you have to correct the value of k, i.e., if the length of the string is a power of 2, reduce k by half, else multiply k by 2. 
You can remove any k characters.

Note: If it is not possible to remove k (the value of k after correction) characters or if the resulting string is empty return -1.

Examples:

Input: s = "fooland", k = 2
Output: "and" 
Explanation: As the size of the string = 7 which is not a power of 2, hence k = 4. After removing 4 characters from the given string, the lexicographically smallest string is "and".
Input: s = "code", k = 4
Output: "cd"
Explanation: As the length of the string = 4, which is 2 to the power 2, hence k = 2. Hence, lexicographically smallest string after removal of 2 characters is "cd".
Constraints:
1 ≤ n ≤ 105
1 ≤ k ≤ 105   */


class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        int n = s.size();

        // Check if n is power of 2
        if ((n & (n - 1)) == 0)
            k /= 2;
        else
            k *= 2;

        if (k >= n || n - k <= 0)
            return "-1";

        string st;

        for (char c : s) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        return st.empty() ? "-1" : st;
    }
};

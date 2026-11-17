/*        Repeated Pattern Check

Given a string s made of two characters of 'x' and 'y'. 
The task is to verify whether s is made by concatenating substrings that follow the pattern xnyn (equal number of y's follow equal number of x's).

Examples:

Input: s = "xxyyxy" 
Output: true
Explanation: The string can be split into "xxyy" + "xy". Both substrings contain an equal number of consecutive 'x' and 'y' characters.
Input: s = "xyx"
Output: false
Explanation: The last 'x' cannot form a valid substring because it is not followed by a matching 'y'. 
Constraints:

1 ≤ s.size() ≤ 105
s consists only of the characters x and y   */


class Solution {
public:
    bool findPattern(string& s) {
        int n = s.size();
        int i = 0;

        while (i < n) {
            // Every group must start with x
            if (s[i] != 'x') {
                return false;
            }

            int xCount = 0;
            int yCount = 0;

            // Count consecutive x's
            while (i < n && s[i] == 'x') {
                xCount++;
                i++;
            }

            // Count consecutive y's
            while (i < n && s[i] == 'y') {
                yCount++;
                i++;
            }

            // Both counts must be equal
            if (xCount != yCount) {
                return false;
            }
        }

        return true;
    }
};


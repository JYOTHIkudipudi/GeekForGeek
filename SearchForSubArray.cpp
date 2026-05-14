/*  Search for Subarray

You are given two integer arrays a[] and b[]. Return all the starting indexes of all the occurences of b[] as a subarray in a[].

Examples:

Input: a[] = [2, 4, 1, 0, 4, 1, 1], b[] = [4, 1]
Output: [1, 4]
Explanation: b[] occurs as a subarray in a[] from index 1 to 2 and from index 4 to 5.
Input: a[] = [2, 4, 1, 0, 0, 3], b[] = [0]
Output: [3, 4]
Explanation: b[] occurs as a subarray in a[] from index 3 to 3 and from index 4 to 4.
Input: a[] = [1, 3, 5, 3, 0], b[] = [1, 3, 0]
Output: []
Explanation: There is no subarray occurs as b[] in a[]
Constraints:
1 ≤ a.size() ≤ 106
1 ≤ b.size() ≤ a.size()
0 ≤ b[i], a[i] ≤ 104   */

class Solution {
public:
    
    vector<int> computeLPS(vector<int>& pat) {
        int m = pat.size();
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    vector<int> search(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        vector<int> lps = computeLPS(b);
        vector<int> ans;

        int i = 0; // index for a
        int j = 0; // index for b

        while (i < n) {

            if (a[i] == b[j]) {
                i++;
                j++;
            }

            if (j == m) {
                ans.push_back(i - j);
                j = lps[j - 1];
            }
            else if (i < n && a[i] != b[j]) {

                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return ans;
    }
};

/*  Substrings with more 1's than 0's
Difficulty: HardAccuracy: 57.87%Submissions: 22K+Points: 8
Given a binary string s consists only of 0s and 1s. Calculate the number of substrings that have more 1s than 0s.

Examples:

Input: s = "011"
Output: 4
Explanation: There are 4 substring which has more 1s than 0s. i.e "011","1","11" and "1"
Input: s = "0000"
Output: 0
Explanation: There is no substring with more 1s than 0s
Constraints:
1 < |s| <  6 * 104  */

class Solution {
public:
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & (-idx);
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & (-idx);
            }
            return sum;
        }
    };

    int countSubstring(string &s) {
        int n = s.size();

        vector<int> pref(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + (s[i - 1] == '1' ? 1 : -1);
        }

        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick ft(vals.size());

        long long ans = 0;

        for (int x : pref) {
            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;

            // Count previous prefix sums strictly smaller
            ans += ft.query(idx - 1);

            ft.update(idx, 1);
        }

        return (int)ans;
    }
};

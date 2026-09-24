/* Maximum Height Disc Stack

Given two arrays r[] and h[] of size n, where r[i] and h[i] represent the radius and height of the i-th circular disc, respectively.

A disc can be placed above another disc only if both its radius and height are strictly smaller than those of the disc below it.

Find the maximum possible height of a stack that can be formed using the given discs. Each disc can be used at most once.

Examples:

Input: r[] = [5, 7, 3], h[] = [6, 5, 4]
Output: 10
Explanation: The discs (3, 4) and (5, 6) form a valid stack. Therefore, the maximum possible height is 4 + 6 = 10.
Input: r[] = [3, 7], h[] = [7, 4]
Output: 7
Explanation: Neither disc can be placed above the other because both required dimensions are not strictly smaller. Therefore, the maximum possible height is 7.
Constraints:

1 ≤ r.size(), h.size() ≤ 105
1 ≤ r[i], h[i] ≤ 1000 */

class Solution {
public:
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        int n = r.size();

        vector<pair<int, int>> discs;
        vector<int> heights;

        for (int i = 0; i < n; i++) {
            discs.push_back({r[i], h[i]});
            heights.push_back(h[i]);
        }

        // Coordinate compression of heights
        sort(heights.begin(), heights.end());
        heights.erase(unique(heights.begin(), heights.end()), heights.end());

        // Sort by radius
        sort(discs.begin(), discs.end());

        int m = heights.size();
        vector<int> bit(m + 1, 0);

        auto query = [&](int idx) {
            int res = 0;
            while (idx > 0) {
                res = max(res, bit[idx]);
                idx -= idx & -idx;
            }
            return res;
        };

        auto update = [&](int idx, int val) {
            while (idx <= m) {
                bit[idx] = max(bit[idx], val);
                idx += idx & -idx;
            }
        };

        int ans = 0;

        /*
            Process equal-radius discs together.
            This is important because radius must be STRICTLY smaller.
        */
        for (int i = 0; i < n; ) {
            int j = i;

            while (j < n && discs[j].first == discs[i].first)
                j++;

            vector<pair<int, int>> updates;

            for (int k = i; k < j; k++) {
                int height = discs[k].second;

                int pos = lower_bound(
                    heights.begin(),
                    heights.end(),
                    height
                ) - heights.begin() + 1;

                // Only heights strictly smaller than current height
                int best = query(pos - 1);

                int current = best + height;

                ans = max(ans, current);

                updates.push_back({pos, current});
            }

            // Update only after processing the whole radius group
            for (auto [pos, value] : updates) {
                update(pos, value);
            }

            i = j;
        }

        return ans;
    }
};

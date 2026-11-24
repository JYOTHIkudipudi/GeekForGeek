/*    Two Pairs with Same Sum
Given an array arr[] of positive integers, find four indices a, b, c, and d such that arr[a] + arr[b] = arr[c] + arr[d], where a, b, c, d are all distinct indices.

If multiple such quadruplets exist, return the one that is lexicographically smallest when the indices are considered in the order a, b, c, d.
If no such quadruplet exists, return {-1, -1, -1, -1}. 
Ensure a < b and c < d, and the pair (a, b) is lexicographically smaller than the pair (c, d).
Examples:

Input: arr[] = [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5]
Explanation: arr[0] + arr[2] = 3 + 7 = 10, arr[3] + arr[5] = 1 + 9 = 10. 
This is the lexicographically smallest such quadruplet of indices.
Input: arr[] = [1, 2, 3, 3]
Output: [-1, -1, -1, -1]
Explanation: No two distinct pairs of indices produce the same sum.
Constraints:

4 ≤ arr.size() ≤ 103
1 ≤ arr[i] ≤ 107   */
class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {
        int n = arr.size();

        struct P { long long s; int a, b; };
        vector<P> v;
        v.reserve((size_t)n * (n - 1) / 2);

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                v.push_back({(long long)arr[i] + arr[j], i, j});

        // stable sort by sum keeps (a, b) lexicographic order within a group
        stable_sort(v.begin(), v.end(),
                    [](const P& x, const P& y) { return x.s < y.s; });

        vector<int> best = {-1, -1, -1, -1};
        int m = v.size();

        for (int l = 0; l < m;) {
            int r = l;
            while (r < m && v[r].s == v[l].s) r++;

            bool found = false;
            for (int i = l; i < r && !found; i++) {
                for (int j = i + 1; j < r; j++) {
                    if (v[i].a != v[j].a && v[i].a != v[j].b &&
                        v[i].b != v[j].a && v[i].b != v[j].b) {
                        vector<int> cand = {v[i].a, v[i].b, v[j].a, v[j].b};
                        if (best[0] == -1 || cand < best) best = cand;
                        found = true;
                        break;
                    }
                }
            }
            l = r;
        }

        return best;
    }
};

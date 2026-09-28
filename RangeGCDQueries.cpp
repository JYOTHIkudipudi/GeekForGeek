/*  Range GCD Queries

Given an integer array arr[] and a 2D array queries[][] containing q queries, where each query is one of the following two types:

Type 1: [0, l, r] -> Return the GCD of all elements in the range [l, r] (both inclusive).
Type 2: [1, index, value] -> Update arr[index] to value.
Return an array containing the answers to all Type 1 queries in the order they appear in queries[][].

Note: Use 0-based indexing.

Examples:

Input: arr[] = [2, 3, 4, 6, 8, 16], q = 3, queries[][] = [[0, 0, 2], [1, 3, 8], [0, 2, 5]]
Output: [1, 4]
Explanation: Initially, arr[] = [2, 3, 4, 6, 8, 16].
Query [0, 0, 2]: Find the GCD of the subarray arr[0...2] = [2, 3, 4]. The GCD is 1.
Query [1, 3, 8]: Update arr[3] from 6 to 8. The array becomes [2, 3, 4, 8, 8, 16].
Query [0, 2, 5]: Find the GCD of the subarray arr[2...5] = [4, 8, 8, 16]. The GCD is 4.
Therefore, the answers to all Type 0 queries are [1, 4].
Input: arr[] = [12, 18, 24, 30, 36], q = 4, queries[][] = [[0, 1, 3], [1, 2, 15], [0, 0, 2], [0, 2, 4]]
Output: [6, 3, 3]
Explanation: Initially, arr[] = [12, 18, 24, 30, 36].
Query [0, 1, 3]: Find the GCD of the subarray arr[1...3] = [18, 24, 30]. The GCD is 6.
Query [1, 2, 15]: Update arr[2] from 24 to 15. The array becomes [12, 18, 15, 30, 36].
Query [0, 0, 2]: Find the GCD of the subarray arr[0...2] = [12, 18, 15]. The GCD is 3.
Query [0, 2, 4]: Find the GCD of the subarray arr[2...4] = [15, 30, 36]. The GCD is 3.
Therefore, the answers to all Type 0 queries are [6, 3, 3].

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ q ≤ 105
0 ≤ l, r, index ≤ arr.size()-1
1 ≤ arr[i], value ≤ 105   */

class Solution {
public:
    
    vector<int> seg;

    void build(int node, int l, int r, vector<int>& arr) {
        if (l == r) {
            seg[node] = arr[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, arr);
        build(2 * node + 1, mid + 1, r, arr);

        seg[node] = gcd(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            seg[node] = value;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, value);
        else
            update(2 * node + 1, mid + 1, r, idx, value);

        seg[node] = gcd(seg[2 * node], seg[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        
        // Completely outside
        if (r < ql || l > qr)
            return 0;

        // Completely inside
        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        int left = query(2 * node, l, mid, ql, qr);
        int right = query(2 * node + 1, mid + 1, r, ql, qr);

        return gcd(left, right);
    }

    vector<int> processQueries(vector<int>& arr,
                               vector<vector<int>>& queries) {

        int n = arr.size();

        seg.resize(4 * n);

        // Build Segment Tree
        build(1, 0, n - 1, arr);

        vector<int> ans;

        for (auto &q : queries) {

            if (q[0] == 0) {
                // Range GCD
                int l = q[1];
                int r = q[2];

                ans.push_back(
                    query(1, 0, n - 1, l, r)
                );
            }
            else {
                // Point Update
                int index = q[1];
                int value = q[2];

                update(1, 0, n - 1, index, value);
            }
        }

        return ans;
    }
};

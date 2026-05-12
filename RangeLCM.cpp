/*   Range LCM Queries

Given an array arr[]  and a list of queries queries[][]. Each query can be one of the following two types:

Update Query: [1, index, value] --> Update the element at position index in the array to the given value.
Range Query: [2, L, R] --> Compute and return the Least Common Multiple (LCM) of all elements in the subarray from index L to R (inclusive).
Process all queries sequentially and return a list containing the results of all Type 2 queries.

Note: All operations follow 0-based indexing.

Examples :

Input: arr[] = [2, 3, 4, 6, 8, 16], queries[][] = [[2, 0, 2], [1, 3, 8], [2, 2, 5]]
Output: [12, 16]
Explanation: The queries are processed sequentially, updating the array when required.
[2, 0, 2]: LCM of [2, 3, 4] = 12
[1, 3, 8]: array becomes [2, 3, 4, 8, 8, 16]
[2, 2, 5]: LCM of [4, 8, 8, 16] = 16
Input: arr[] = [1, 2, 3, 4],  queries[][] = [[2, 0, 3], [1, 0, 5], [2, 0, 1]]
Output: [12, 10]
Explanation: The queries are processed sequentially, updating the array when required.
[2, 0, 3]: LCM of [1, 2, 3, 4] = 12
[1, 0, 5]: array becomes [5, 2, 3, 4]
[2, 0, 1]: LCM of [5, 2] = 10

Constraints:
1 ≤ arr.size() ≤ 104
1 ≤ queries.size() ≤ 105
0 ≤ L ≤ R ≤ arr.size() - 1
0 ≤ index ≤ arr.size() - 1
1 ≤ arr[i], value ≤ 104  */


class Solution {
  public:
    
    vector<long long> seg;
    
    long long findLCM(long long a, long long b) {
        return (a / __gcd(a, b)) * b;
    }
    
    void build(int idx, int low, int high, vector<int>& arr) {
        
        if(low == high) {
            seg[idx] = arr[low];
            return;
        }
        
        int mid = (low + high) / 2;
        
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        
        seg[idx] = findLCM(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    
    void update(int idx, int low, int high, int pos, int val) {
        
        if(low == high) {
            seg[idx] = val;
            return;
        }
        
        int mid = (low + high) / 2;
        
        if(pos <= mid)
            update(2 * idx + 1, low, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, high, pos, val);
            
        seg[idx] = findLCM(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    
    long long query(int idx, int low, int high, int l, int r) {
        
        // no overlap
        if(r < low || high < l)
            return 1;
            
        // complete overlap
        if(l <= low && high <= r)
            return seg[idx];
            
        int mid = (low + high) / 2;
        
        long long left = query(2 * idx + 1, low, mid, l, r);
        long long right = query(2 * idx + 2, mid + 1, high, l, r);
        
        return findLCM(left, right);
    }
    
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        
        int n = arr.size();
        
        seg.resize(4 * n);
        
        build(0, 0, n - 1, arr);
        
        vector<long long> ans;
        
        for(auto &q : queries) {
            
            // Update Query
            if(q[0] == 1) {
                int index = q[1];
                int value = q[2];
                
                update(0, 0, n - 1, index, value);
            }
            
            // Range LCM Query
            else {
                int l = q[1];
                int r = q[2];
                
                ans.push_back(query(0, 0, n - 1, l, r));
            }
        }
        
        return ans;
    }
};

/*  Count Indices That Escape Array

Given an array arr[], where arr[i] represents the exact number of steps to move from index i. 
An index is considered good if repeatedly following the jumps eventually takes you outside the array. Otherwise, 
if the jumps result in an infinite loop, the index is considered bad.

A positive value indicates a move to the right
A negative value indicates a move to the left.
A 0 value means no move and considered bad.
Return the number of good indices.

Examples:

Input: [2, 3, -1, 2, -2, 4, 1]
Output: 3
Explanation: Indices 3, 5, and 6 are good because their jump sequences eventually leave the array. 
Indices 1, 2, and 4 form a cycle, while index 0 eventually enters this cycle through index 2. Hence, the total number of good indices is 3.
 
Input: [1, 0, -3, 0, -5, 0]
Output: 2
Explanation: Indices 2 and 4 are good because their jumps take them outside the array. Indices 1, 3, and 5 are bad because their jumps are zero.
  Index 0 is also bad because it jumps to index 1, which is a dead end. Hence, the total number of good indices is 2.
  
Constraints:

1 ≤ arr.size() ≤ 105
-105 ≤ arr[i] ≤ 105  */


class Solution {
  public:
    int goodIndices(vector<int> &arr) {
        int n = arr.size();

        vector<int> state(n, 0);
        vector<bool> good(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (state[i] == 2)
                continue;

            vector<int> path;
            int curr = i;

            while (curr >= 0 && curr < n &&
                   state[curr] == 0) {
                state[curr] = 1;
                path.push_back(curr);
                curr += arr[curr];
            }

            bool escapes;

            if (curr < 0 || curr >= n) {
                escapes = true;
            } else if (state[curr] == 1) {
                escapes = false;
            } else {
                escapes = good[curr];
            }

            for (int j = path.size() - 1; j >= 0; j--) {
                good[path[j]] = escapes;
                state[path[j]] = 2;
            }
        }

        for (int i = 0; i < n; i++) {
            if (good[i])
                ans++;
        }

        return ans;
    }
};

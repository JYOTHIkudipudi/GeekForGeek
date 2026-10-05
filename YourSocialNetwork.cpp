/*  Your Social Network
Difficulty: MediumAccuracy: 68.37%Submissions: 8K+Points: 4Average Time: 20m
Geek is creating a social networking site called Geeksbook with n users numbered from 1 to n. Each user i (2 ≤ i ≤ n) has exactly one friend, and that friend must have a smaller user number than i. User 1 has no friend. The friends of users 2 to n are given in an array arr[] of size n - 1, where:

arr[0] is the friend of user 2.
arr[1] is the friend of user 3.
...
arr[i - 2] is the friend of user i.
The relationship is one-way. A user can reach another user by repeatedly following their friend's link. For every user i from 2 to n, find all users j (1 ≤ j < i) that can be reached from i. For every reachable pair (i, j), create an array [i, j, k] where:

i is the starting user.
j is the reachable user.
k is the number of links that must be followed to reach j from i.
The result should contain these arrays in the following order:

Process users i from 2 to n.
For each user i, consider users j from 1 to i - 1 in increasing order.
Include [i, j, k] only if j is reachable from i.

Return a 2D array containing information about all reachable pairs.

Examples:

Input: arr[] = [1, 2]
Output: [[2, 1, 1], [3, 1, 2], [3, 2, 1]]
Explanation: The links are 2 → 1 and 3 → 2. User 2 can reach user 1 in 1 link. User 3 can reach user 1 in 2 links. User 3 can reach user 2 in 1 link.
Input: arr[] = [1, 1]
Output: [[2, 1, 1], [3, 1, 1]]
Explanation: The links are 2 → 1 and 3 → 1. User 2 can reach user 1 in 1 link. User 3 can reach user 1 in 1 link.
Constraints:

2 ≤ arr.size() ≤ 500
1 ≤ arr[i] ≤ 500   */

class Solution {
  public:
    vector<vector<int>> socialNetwork(vector<int>& arr) {
        
        int n = arr.size() + 1;
        
        // friend[i] = friend of user i
        vector<int> fr(n + 1);
        
        for (int i = 2; i <= n; i++) {
            fr[i] = arr[i - 2];
        }
        
        vector<vector<int>> ans;
        
        // For every user
        for (int i = 2; i <= n; i++) {
            
            int current = i;
            int steps = 0;
            
            // Keep following the friend chain
            while (current != 1) {
                
                current = fr[current];
                steps++;
                
                // We reached user 'current'
                // Store temporarily
                ans.push_back({i, current, steps});
            }
        }
        
        // The problem requires j in increasing order.
        // So sort according to:
        // 1. starting user i
        // 2. reachable user j
        sort(ans.begin(), ans.end(), [](const vector<int>& a,
                                        const vector<int>& b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        
        return ans;
    }
};

/* Max Path Sum Between Two Leaves
Given the root of a binary tree, where each node contains an integer value,
find the maximum possible path sum between any two leaf nodes. If the tree has fewer than two leaf nodes, return -1.

Examples:

Input: root = [3, 4, 5, -10, 4, N, N]
                   
Output: 16
Explanation: 

The leaf nodes are -10, 4 (right child of 4), and 5.
Possible paths between leaf nodes are:
-10 -> 4 -> 3 -> 5 = -10 + 4 + 3 + 5 = 2
-10 -> 4 -> 4 = -10 + 4 + 4 = -2
4 -> 4 -> 3 -> 5 = 4 + 4 + 3 + 5 = 16
Hence, the maximum path sum is obtained from the path 4 -> 4 -> 3 -> 5, giving 16.
Input: root = [-15, 5, 6, -8, 1, 3, 9, 2, -3, N, N, N, N, N, 0, N, N, N, N, 4, -1, N, N, 10]

Output: 27
Explanation: 

The leaf nodes are 2, -3, 1, 4, and 10.
Some possible paths between leaves are:
2 -> -8 -> 5 -> 1 = 2 + (-8) + 5 + 1 = 0
-3 -> -8 -> 5 -> 1 = -3 + (-8) + 5 + 1 = -5
2 -> -8 -> 5 -> -15 -> 6 -> 3 = 2 + (-8) + 5 + (-15) + 6 + 3 = -7
1 -> 5 -> -15 -> 6 -> 9 -> 0 -> 4 = 1 + 5 + (-15) + 6 + 9 + 0 + 4 = 10
3 -> 6 -> 9 -> 0 -> -1 -> 10 = 3 + 6 + 9 + 0 + (-1) + 10 = 27
Hence, the maximum path sum is obtained from the path 3 -> 6 -> 9 -> 0 -> -1 -> 10, giving 27.
Input: root = [3, 4, 1, -10, 4, N, N] 
                         
Output: 12
Explanation:

The leaf nodes are -10, 4 (right child of 4), and 1.
Possible paths between leaf nodes are:
-10 -> 4 -> 4 = -10 + 4 + 4 = -2
-10 -> 4 -> 3 -> 1 = -10 + 4 + 3 + 1 = -2
4 -> 4 -> 3 -> 1 = 4 + 4 + 3 + 1 = 12
Hence, the maximum path sum is obtained from the path 4 -> 4 -> 3 -> 1, giving 12.
Constraints:

0 ≤ size of binary tree ≤ 104
-103 ≤ node.data ≤ 103
   */

/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
  public:
    
    int ans = INT_MIN;
    
    int solve(Node* root) {
        
        // Leaf node
        if (root->left == nullptr && root->right == nullptr)
            return root->data;
        
        // Only right child
        if (root->left == nullptr)
            return root->data + solve(root->right);
        
        // Only left child
        if (root->right == nullptr)
            return root->data + solve(root->left);
        
        // Both children exist
        int left = solve(root->left);
        int right = solve(root->right);
        
        // Path between two leaves through current node
        ans = max(ans, left + root->data + right);
        
        // Best path from current node to one leaf
        return root->data + max(left, right);
    }
    
    int maxPathSum(Node *root) {
        
        if (root == nullptr)
            return -1;
        
        solve(root);
        
        // Less than two leaves
        if (ans == INT_MIN)
            return -1;
        
        return ans;
    }
};

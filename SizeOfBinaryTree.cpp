/*  Size of Binary Tree

Given the root of a binary tree, return the size of the tree. The size of a binary tree is the total number of nodes in the tree.

Examples:

Input:      

Output:  3
Explanation: There are 3 nodes in the given binary tree, so its size is 3.
Input:

Output: 6
Explanation: There are 6 nodes in the given binary tree, so its size is 6.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105  */

#include <queue>

class Solution {
  public:
    int getSize(Node* root) {
        if (root == NULL) return 0;

        queue<Node*> q;
        q.push(root);
        int count = 0;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            count++;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        return count;
    }
};

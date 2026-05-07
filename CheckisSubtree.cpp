/* Check if subtree

Given two binary trees with roots root1 (for tree T) and root2 (for tree S), each containing at most N nodes. Determine whether tree S is a subtree of tree T.

Return true if S is a subtree of T, otherwise return false.

Note: A tree S is considered a subtree of T if there exists a node in T such that the subtree rooted at that node is identical to S. Two trees are identical if they have the same structure and the same node values.

Examples:

Input: root1 = [1, 2, 3, N, N, 4], root2 = [3, 4]
             
Output: true 
Explanation: In the tree rooted at root1, the subtree starting at node 3 is identical to the tree rooted at root2 (same structure and node values). Hence, root2 is a subtree of root1, so the output is true.
Input: root1 = [26, 10, N, 20, 30, 40, 60], root2 = [26, 10, N, 20, 30, 40, 60]
                        
Output: true 
Explanation: Both root1 and root2 represent identical trees. So, root2 is a subtree of root1, and the output is true.
Constraints:
1 ≤ n ≤ 103
1 ≤ value of nodes ≤ 104  */
/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
private:
    bool isSameTree(Node* root1, Node* root2) {
        // Both null = identical
        if (root1 == nullptr && root2 == nullptr) return true;
        // One null = not identical  
        if (root1 == nullptr || root2 == nullptr) return false;
        // Values differ OR recurse fails = not identical
        if (root1->data != root2->data) return false;
        return isSameTree(root1->left, root2->left) && 
               isSameTree(root1->right, root2->right);
    }
    
public:
    bool isSubTree(Node *root1, Node *root2) {
        // Empty subtree is always subtree
        if (root2 == nullptr) return true;
        // Main tree empty = false
        if (root1 == nullptr) return false;
        
        // Check current node OR search children
        return isSameTree(root1, root2) || 
               isSubTree(root1->left, root2) || 
               isSubTree(root1->right, root2);
    }
};

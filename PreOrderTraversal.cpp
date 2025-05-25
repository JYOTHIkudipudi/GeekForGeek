/*  Preorder Traversal

Given a binary tree, find its preorder traversal.

Examples:

Input:
        1      
      /          
    4    
  /    \   
4       2
Output: [1, 4, 4, 2]
Input:
       6
     /   \
    3     2
     \   / 
      1 2
Output: [6, 3, 1, 2, 2] 
Input:
         8
       / \
      3   10
     / \    \
    1   6   14
       / \   /
      4   7 13
Output: [8, 3, 1, 6, 4, 7, 10, 14, 13]
Constraints:
1 <= number of nodes <= 105
0 <= node->data <= 106 */

class Solution {
  public:
    // Function to return a list containing the preorder traversal of the tree.
    vector<int> preorder(Node* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }
  
  private:
    void preorderHelper(Node* node, vector<int>& result) {
        if (node == nullptr) return;
        
        // Visit root
        result.push_back(node->data);
        // Traverse left subtree
        preorderHelper(node->left, result);
        // Traverse right subtree
        preorderHelper(node->right, result);
    }
};

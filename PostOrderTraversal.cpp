/*  Postorder Traversal

Given a binary tree, find the Postorder Traversal of it and return a list containing the postorder traversal of the given tree.

Examples:
Input: root = [19, 10, 8, 11, 13]
        19
     /     \
    10      8
  /    \
 11    13
Output: [11, 13, 10, 8, 19]
Input: root = [11, 15, N, 7]
          11
         /
       15
      /
     7
Output: [7, 15, 11]
Constraints:
1 <= number of nodes <= 105
0 <= node->data <= 106  */

class Solution{
vector<int> postOrder(Node* root) {
        vector<int> result;
        postOrderHelper(root, result);
        return result;
    }
    
  private:
    void postOrderHelper(Node* node, vector<int>& result) {
        if (node == nullptr) return;
        
        postOrderHelper(node->left, result);    // Left
        postOrderHelper(node->right, result);   // Right
        result.push_back(node->data);           // Root
    }
};

/*  Preorder Traversal
Given the root of a binary tree, your task is to return its Preorder traversal.

Note: A preorder traversal first visits the node, then visits the left child (including its entire subtree), and finally visits the right child (including its entire subtree).

Examples:

Input: root = [1, 4, N, 4, 2]
   
Output: [1, 4, 4, 2]
Explanation: The preorder traversal of the given binary tree is [1, 4, 4, 2]
Input: root = [6, 3, 2, N, 1, 2, N]
    
Output: [6, 3, 1, 2, 2] 
Explanation: The preorder traversal of the given binary tree is [6, 3, 1, 2, 2] 
Constraints:
1 ≤ number of nodes ≤ 3*104
0 ≤ node->data ≤ 105  */

/* A binary tree node has data, pointer to left child
   and a pointer to right child

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
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

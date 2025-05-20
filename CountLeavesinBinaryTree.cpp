/*  Given a Binary Tree of size n, You have to count leaves in it. For example, there are two leaves in the following tree

        1
     /      \
   10      39
  /
5
 

Examples:

Input:
Given Tree is 
               4
             /   \
            8     10
           /     /   \
          7     5     1
         /
        3 
Output: 3
Explanation: Three leaves are 3, 5 and 1.
Input:
Given Tree is
          50
        /    \
      30      70
     /  \    /  \
    20   40 60   80
             \
             65
Output: 4
Explanation: Four leaves are 20, 40, 65 and 80.
Input:
Given Tree is 
          30
        /    \
      25      35
     /  \      \
    20   28     40
        /
       27
Output: 3
Explanation: Three leaves are 20, 27 and 40.

 Constraints:
1<= number of nodes <= 105
1<= node->data <= 105  */

class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // Base Case: If root is null, there are no leaves
        if (root == nullptr)
            return 0;
        
        // If both left and right children are null, it's a leaf node
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        
        // Recur for left and right subtrees
        return countLeaves(root->left) + countLeaves(root->right);
    }
};

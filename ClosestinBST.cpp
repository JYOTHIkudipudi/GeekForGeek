/*  Closest in BST

Given root of a Binary Search Tree (BST) and an integer k, find the minimum absolute difference between k and the value of any node in the BST.

Examples:

Input: root = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4], k = 13

Output: 2
Explanation: The node with value 11 is closest to k = 13. So, the minimum absolute difference is |11 - 13| = 2.
Input: root = [8, 1, 9, N, 4, N, 10, 3], k = 9

Output: 0
Explanation: The node with value 9 is closest to k = 9. So, the minimum absolute difference is |9 - 9| = 0.
Constraints:

1 ≤ size of binary tree, k ≤ 105
0 ≤ Node.data ≤ 105
 */

class Solution {
public:
    int minDiff(Node* root, int k) {
        int ans = INT_MAX;

        while (root != NULL) {
            ans = min(ans, abs(root->data - k));

            if (root->data == k) {
                return 0;
            }
            else if (k < root->data) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }

        return ans;
    }
};

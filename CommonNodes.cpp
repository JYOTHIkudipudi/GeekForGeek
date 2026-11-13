/*   Common Nodes in Two BSTs

Given the roots r1 and r2 of two Binary Search Trees (BST), find all nodes that are present in both trees i.e. the intersection nodes of the two BSTs.

Return the common node values in sorted order.

Examples:
Input: r1 = [5, 1, 10, 0, 4, 7, N, N, N, N, N, N, 9], r2 = [10, 7, 20, 4, 9, N, N]  
Output: [4, 7, 9, 10]
Explanation: The values present in both BSTs are 4, 7, 9, and 10. Hence, the answer is [4, 7, 9, 10].
Input: r1 = [10, 2, 11, 1, 3, N, N], r2 = [2, 1, 3]
Output: [1, 2, 3]
Explanation: The values 1, 2, and 3 are present in both BSTs. Hence, the answer is [1, 2, 3].
Constraints:
1 ≤ size of binary trees ≤ 105
0 ≤ Node.data ≤ 109
*/


class Solution {
public:
    void inorder(Node* root, vector<int>& arr) {
        if (root == nullptr) return;

        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    vector<int> findCommon(Node* r1, Node* r2) {

        vector<int> a, b, ans;

        inorder(r1, a);
        inorder(r2, b);

        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {

            if (a[i] == b[j]) {
                ans.push_back(a[i]);
                i++;
                j++;
            }
            else if (a[i] < b[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return ans;
    }
};

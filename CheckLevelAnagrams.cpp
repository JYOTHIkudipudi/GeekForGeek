/* Check Level Anagrams in Binary Trees
Given the roots of two binary trees root1 and root2, check whether the nodes at every corresponding level of the two trees are anagrams of each other.

Two levels are considered anagrams if they contain the same node values with the same frequencies, regardless of their order.

Examples:

Input: root1 = [1, 3, 2, N, N, 5, 4], root2 = [1, 2, 3, 4, 5, N, N]

Output: true
Explanation: 
Level 0: [1] and [1]
Level 1: [3, 2] and [2, 3]
Level 2: [5, 4] and [4, 5]
The node values at every corresponding level are anagrams of each other. Hence, the answer is true.
Input: root1 = [1, 2, 3, 5, 4], root2 = [1, 2, 4, 5, 3]

Output: false
Explanation: 
Level 0: [1] and [1]
Level 1: [2, 3] and [2, 4]
Since the node values at level 1 are not anagrams, the answer is false.
Constraints:

1 ≤ size of binary tree ≤ 105
1 ≤ node.data ≤ 106
The character N represents a null child.   */

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        if (root1 == nullptr || root2 == nullptr)
            return root1 == root2;

        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int n1 = q1.size();
            int n2 = q2.size();

            // Different number of nodes at this level
            if (n1 != n2)
                return false;

            unordered_map<int, int> freq;

            // Process level of tree 1
            for (int i = 0; i < n1; i++) {
                Node* curr = q1.front();
                q1.pop();

                freq[curr->data]++;

                if (curr->left)
                    q1.push(curr->left);

                if (curr->right)
                    q1.push(curr->right);
            }

            // Process level of tree 2
            for (int i = 0; i < n2; i++) {
                Node* curr = q2.front();
                q2.pop();

                freq[curr->data]--;

                if (curr->left)
                    q2.push(curr->left);

                if (curr->right)
                    q2.push(curr->right);
            }

            // Every frequency must become zero
            for (auto &p : freq) {
                if (p.second != 0)
                    return false;
            }
        }

        // One tree may have more levels than the other
        return q1.empty() && q2.empty();
    }
};

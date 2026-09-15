/*  Visit Leaves with Budget

Given a binary tree and an integer k, where you start from the root at level 1. 
The cost of visiting a leaf node is equal to the level of that leaf node. You can visit any number of leaf nodes,
but the total cost of visiting them must not exceed k.

Return the maximum number of leaf nodes that can be visited within the given budget.

Examples:

Input: root[] = [10, 8, 2, 3, N, 3, 6, N, N, N, 4], k = 8

Output: 2
Explanation:
Cost For visiting Leaf Node 3: 3
Cost For visiting Leaf Node 4: 4
Cost For visiting Leaf Node 6: 3
To maximize the number of visited leaves, choose the two cheapest leaves: Cost = 3 + 3 = 6 ≤ 8. 
Thus, the maximum number of leaf nodes that can be visited is 2.
Input: root[] = [1, 2, 3, 4, 5, 6, 7], k = 5

Output: 1
Explanation: The leaf nodes are 4, 5, 6 and 7, and all are at level 3. Therefore, visiting each leaf costs 3. With a budget of 5, we can visit only one leaf because: 3 ≤ 5, but 3 + 3 > 5. Thus, the maximum number of leaf nodes that can be visited is 1.
Input: root[] = [1], k = 1         
Output: 1
Explanation: The root node is also a leaf node and is at level 1. Therefore, its visiting cost is 1. Thus, the maximum number of leaf nodes that can be visited is 1.
Constraints:

1 ≤ size of binary tree ≤ 105
1 ≤ k ≤ 104
  */

class Solution {
  public:
    void dfs(Node* root, int level, vector<int>& costs) {
        if (root == nullptr)
            return;

        // Leaf node
        if (root->left == nullptr && root->right == nullptr) {
            costs.push_back(level);
            return;
        }

        dfs(root->left, level + 1, costs);
        dfs(root->right, level + 1, costs);
    }

    int getCount(Node *root, int k) {
        vector<int> costs;

        // Root starts at level 1
        dfs(root, 1, costs);

        // Cheapest leaves should be selected first
        sort(costs.begin(), costs.end());

        int count = 0;

        for (int cost : costs) {
            if (k < cost)
                break;

            k -= cost;
            count++;
        }

        return count;
    }
};

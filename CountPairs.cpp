/*  Count Pairs Violating BST Property

Given root of a binary tree in which all node values are distinct, count pairs of nodes that violate any of the following Binary Search Tree (BST) properties.


All values in the left subtree are strictly smaller.
All values in the right subtree are strictly greater.
Examples:

Input: root[] = [10, 50, 40, N, N, 20, 30]
2056958715
Output: 5
Explanation: Pairs violating BST property are:-
(10, 50), 10 should be greater than its left child value.
(40, 30), 40 should be less than its right child value.
(50, 20), (50, 30) and (50, 40), maximum of left subtree of 10 is 50 greater than 20, 30 and 40 of its right subtree.
Input: root[] = [80, 40, 30, 70, N, 60, 50]

Output: 10
Explanation: There are total 10 pairs (80, 30), (80, 60), (80, 50), (30, 60), (40, 70), (40, 30), (40, 50), 
(70, 30), (70, 60), (70, 50) which violate the BST properties.
Constraints:

1 ≤ size of binary tree ≤ 5*104
1 ≤ node.data ≤ 109
All node values are distinct.
  */


class Solution {
    long long mergeCount(vector<int>& arr, vector<int>& temp,
                         int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;

        long long count = 0;
        count += mergeCount(arr, temp, left, mid);
        count += mergeCount(arr, temp, mid + 1, right);

        int i = left, j = mid + 1, k = left;

        while (i <= mid && j <= right) {
            if (arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                count += mid - i + 1;
            }
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];

        for (int p = left; p <= right; p++) {
            arr[p] = temp[p];
        }

        return count;
    }

public:
    int pairsViolatingBST(Node* root) {
        vector<int> arr;
        stack<Node*> st;
        Node* curr = root;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            arr.push_back(curr->data);
            curr = curr->right;
        }

        int n = arr.size();
        vector<int> temp(n);

        return (int)mergeCount(arr, temp, 0, n - 1);
    }
};

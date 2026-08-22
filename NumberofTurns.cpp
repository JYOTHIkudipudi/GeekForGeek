/* Number of Turns in Binary Tree

Given root of a binary tree and the values of its two nodes p and q, count turns required to travel from node p to q.

A turn occurs whenever the direction of movement changes from left to right or right to left while traversing the tree.
If the path between the two nodes does not involve any turns (i.e., the nodes lie on the same straight path), return -1.
Note: All node values are distinct.

Examples :

Input: root[] = [1, 2, 3, 4, 5, 6, 7, 8, N, N, N, 9, 10], p = 5, q = 10

Output: 4
Explanation: The path from node 5 to node 10 is: 5 -> 2 -> 1 -> 3 -> 6 → 10. Direction changes occur at nodes 2, 1, 3, and 6. Therefore, the number of turns is 4.
Input: root[] = [1, 2, 3, 4, 5, 6, 7, 8, N, N, N, 9, 10], p = 1, q = 4

Output: -1
Explanation: No turn is required since they are in a straight line.
Constraints:
1 ≤ n ≤ 104, n is the number of nodes
1 ≤ node->data ≤ 104
1 ≤ p, q ≤ n  */
class Solution {
  public:
  
    bool findPath(Node* root, int target, string &path) {
        if (root == nullptr)
            return false;
            
        if (root->data == target)
            return true;
        
        // Try going left
        path.push_back('L');
        if (findPath(root->left, target, path))
            return true;
        path.pop_back();
        
        // Try going right
        path.push_back('R');
        if (findPath(root->right, target, path))
            return true;
        path.pop_back();
        
        return false;
    }
    
    int numberOfTurns(Node* root, int p, int q) {
        string pathP = "";
        string pathQ = "";
        
        findPath(root, p, pathP);
        findPath(root, q, pathQ);
        
        // Find common path = path till LCA
        int i = 0;
        
        while (i < pathP.size() && 
               i < pathQ.size() && 
               pathP[i] == pathQ[i]) {
            i++;
        }
        
        string directions = "";
        
        // From p -> LCA, reverse directions
        for (int j = pathP.size() - 1; j >= i; j--) {
            directions += pathP[j];
        }
        
        // From LCA -> q
        for (int j = i; j < pathQ.size(); j++) {
            directions += pathQ[j];
        }
        
        int turns = 0;
        
        for (int j = 1; j < directions.size(); j++) {
            if (directions[j] != directions[j - 1]) {
                turns++;
            }
        }
        
        return turns == 0 ? -1 : turns;
    }
};

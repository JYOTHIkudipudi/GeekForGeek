/*   REVERSE A LINKED LIST 
Given the head of a linked list, the task is to reverse this list and return the reversed head.

Examples:

Input: head: 1 -> 2 -> 3 -> 4 -> NULL
Output: head: 4 -> 3 -> 2 -> 1 -> NULL
 

Input: head: 2 -> 7 -> 10 -> 9 -> 8 -> NULL
Output: head: 8 -> 9 -> 10 -> 7 -> 2 -> NULL

Input: head: 2 -> NULL
Output: 2 -> NULL


Constraints:
1 <= number of nodes, data of nodes <= 105   */



class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;   // Store next node
            curr->next = prev;   // Reverse current node's pointer
            prev = curr;         // Move prev to current
            curr = next;         // Move to next node
        }

        return prev; 
    }
};


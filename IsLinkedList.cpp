/*   Is Linked List Length Even?

Given a linked list, your task is to complete the function isLengthEven() which contains the head of the linked list, 
and check whether the length of the linked list is even or not. Return true if it is even, otherwise false.

Examples:
Input: Linked list: 12->52->10->47->95->0
Output: true
Explanation: The length of the linked list is 6 which is even, hence returned true.
Input: Linked list: 9->4->3
Output: false
Explanation: The length of the linked list is 3 which is odd, hence returned false.
  
Constraints:
1 <= number of nodes <= 105
1 <= elements of the linked list <= 105   */

class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        // Code here
         struct Node* temp = *head;
        bool isEven = true;

        while (temp != nullptr) {
            isEven = !isEven; // toggle on each node
            temp = temp->next;
        }

        return isEven;
    }
};

/*   Array insert at end

Insertion is a basic but frequently used operation. Arrays in most languages can not be dynamically shrinked or expanded. 
Here, we will work with such arrays and try to insert an element at the end of the array. 

You need to modify the given array arr. The size of the array is given by sizeOfArray. You need to insert an element at the end. 
Array already have the sizeofarray -1 elements. Find Kth Rotation

Examples :

Input: sizeOfArray = 6, arr[] = {1, 2, 3, 4, 5}, element = 90
Output: 1 2 3 4 5 90
Explanation: After inserting 90 at the end, we have array elements as 1 2 3 4 5 90.
Input: sizeOfArray = 4, arr[] = {1, 2, 3}, element = 50
Output: 1 2 3 50
Explanation: After inserting 50 at the end, we have array elements as 1 2 3 50.
Your Task:
You don't need to read input or print anything. You only need to complete the function insertAtEnd() that takes arr, sizeOfArray, element as input and modifies the given array arr as per requirements. The driver code takes care of the printing.

Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).

Constraints:
1 <= sizeOfArray <= 1000
0 <= element, arri <= 106   */

// elements.
void insertAtEnd(int arr[], int sizeOfArray, int element) {
    // Your code here
        arr[sizeOfArray - 1] = element;

}

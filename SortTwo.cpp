/* Sort Two Parts Sorted


Given an integer array **arr[]** where the two parts around a break point are individually sorted, merge them into a single sorted array. 
The break point can be anywhere in the array, including at the beginning or end.


**Input:&#x20;**&#x61;rr[] = [-4, 6, 9, -1, 3] 
  **Output:&#x20;**[-4, -1, 3, 6, 9] 
  **Explanation:&#x20;**[-4, 6, 9] and [-1, 3] are sorted in the original array. The overall sorted version is [-4 -1 3 6 9].

**Input:&#x20;**&#x61;rr[] = [10, 20, 30] 
  **Output:&#x20;**[10, 20, 30]
  **Explanation:&#x20;**&#x4F;ne part is empty and the other part is whole array which is already sorted.

**Constraints:**

1 ≤ arr.size() ≤ 106\
-105 ≤ arr[i] ≤ 105\
  */
class Solution {
public:
    void mergeTwoParts(vector<int>& arr) {
        sort(arr.begin(), arr.end());
    }
};

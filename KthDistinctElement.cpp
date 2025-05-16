/*         K-th distinct element
Difficulty: BasicAccuracy: 38.6%Submissions: 5K+Points: 1
Given an array of n integers. Find the kth distinct element.

Example 1:
Input: 
n = 6, k = 2
arr = {1, 2, 1, 3, 4, 2}
Output:
4
Explanation: 1st distinct element will be 3
and the 2nd distinct element will be 4. As 
both the elements present in the array only 1 
times.
Example 2:
Input: 
n = 6, k = 3
arr = {1, 2, 50, 10, 20, 2}
Output:
10

Your Task:
You don't need to read or print anything. Your task is to complete the function KthDistinct() which takes the array of elements as input parameter
and returns the kth distinct element. If not possible return -1.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constranits:
1 <= length of array <= 105
1 <= elements of array <= 106   */

class Solution {
  public:
    int KthDistinct(vector<int> nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: Count frequency of each element
        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
        }

        // Step 2: Find k-th distinct element (appears exactly once)
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (freq[nums[i]] == 1) {
                count++;
                if (count == k) {
                    return nums[i];
                }
            }
        }

        // Step 3: If k-th distinct element not found
        return -1;
    }
};

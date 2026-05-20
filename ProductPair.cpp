/*  Product Pair

Given an integer array arr[] and an integer target, determine whether there exists a pair of elements in the array whose product is equal to target.

Return true if such a pair exists; otherwise, return false.

Examples:

Input: arr[] = [10, 20, 9, 40], target = 400
Output: true
Explanation: As 10 * 40 = 400, the answer is true.
Input: arr[] = [-10, 20, 9, -40], target = 30
Output: false
Explanation: No pair exists with product 30.
Input: arr[] = [-10, 0, 9, -40], target = 0
Output: true
Explanation: As -10 * 0 = 0, the answer is true.
Constraints:
2 ≤ arr.size ≤ 105
-108 ≤ arr[i] ≤ 108
-1018 ≤ target ≤ 1018  */

class Solution {
  public:
    bool isProduct(vector<int> arr, long long target) {
        unordered_set<long long> s;

        for (long long x : arr) {

            // Special case for target = 0
            if (target == 0) {
                if (x == 0 && !s.empty())
                    return true;

                for (auto val : s) {
                    if (val == 0)
                        return true;
                }
            }

            // Normal case
            if (x != 0 && target % x == 0) {
                long long need = target / x;

                if (s.count(need))
                    return true;
            }

            s.insert(x);
        }

        return false;
    }
};

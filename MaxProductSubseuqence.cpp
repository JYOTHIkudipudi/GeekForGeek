/* Max Product Subsequence of Size K

Difficulty: **Medium**Accuracy: **49.3%**Submissions: **12K+**Points: **4**

Given an array **arr[]** of integers and an integer **k**, find a subsequence of size k whose product is maximum among all possible subsequences of size k. 
Return the maximum product that can be obtained.

**Examples:**

```
Input: arr[] = [1, 2, 0, 3], k = 2
Output: 6
Explanation: Subsequence containing elements {2, 3} gives maximum product: 2*3 = 6
```

```
Input: arr[] = [1, 2, -1, -3, -6, 4], k = 4
Output: 144
Explanation: Subsequence containing {2, -3, -6, 4} gives maximum product: 2*(-3)*(-6)*4 = 144
```

**Constraints:**

arr.size() ≤ 30
-10 ≤ arr[i] ≤ 10
1 ≤ k ≤ arr.size()  */

class Solution {
public:
    int maxProduct(vector<int> &arr, int k) {
        
        const long long INF = 1e18;

        // dpMax[j] = maximum product using j elements
        // dpMin[j] = minimum product using j elements
        vector<long long> dpMax(k + 1, -INF);
        vector<long long> dpMin(k + 1, INF);

        dpMax[0] = 1;
        dpMin[0] = 1;

        for (int x : arr) {
            
            // Go backwards so that each element is used only once
            for (int j = k; j >= 1; j--) {
                
                if (dpMax[j - 1] == -INF)
                    continue;

                long long p1 = dpMax[j - 1] * x;
                long long p2 = dpMin[j - 1] * x;

                dpMax[j] = max(dpMax[j], max(p1, p2));
                dpMin[j] = min(dpMin[j], min(p1, p2));
            }
        }

        return (int)dpMax[k];
    }
};

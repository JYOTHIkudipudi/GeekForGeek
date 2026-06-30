/* Minimum Insert and Delete to Convert
Given two arrays a[] and b[] of size n and m respectively, find the minimum number of insertions and deletions on the array a[], required to make both the arrays identical.

Note: Array b[] is sorted and all its elements are distinct, operations can be performed at any index not necessarily at the end.

Examples :

Input: a[] = [1, 2, 5, 3, 1], b[] = [1, 3, 5]
Output: 4
Explanation:
Delete 2 from a: a[] = [1, 5, 3, 1]
Insert 3 after 1: a[] = [1, 3, 5, 3, 1]
Delete the last two elements: a[] = [1, 3, 5]
Total operations = 1 + 1 + 2 = 4.
Input: a[] = [1, 4], b[] = [1, 4]
Output : 0
Explanation: Both the Arrays are already identical.
 Constraints:
1 ≤ n, m ≤ 105
1 ≤ a[i], b[i] ≤ 105  */

class Solution {
public:
    int minInsAndDel(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> pos;

        for (int i = 0; i < b.size(); i++)
            pos[b[i]] = i;

        vector<int> seq;

        for (int x : a) {
            if (pos.count(x))
                seq.push_back(pos[x]);
        }

        vector<int> lis;

        for (int x : seq) {
            auto it = lower_bound(lis.begin(), lis.end(), x);

            if (it == lis.end())
                lis.push_back(x);
            else
                *it = x;
        }

        int lcs = lis.size();

        return (a.size() - lcs) + (b.size() - lcs);
    }
};

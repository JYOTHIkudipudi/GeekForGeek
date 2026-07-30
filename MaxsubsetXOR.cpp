class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        int n = arr.size();
        int index = 0;

        for (int bit = 31; bit >= 0; bit--) {
            int mx = -1;

            for (int i = index; i < n; i++) {
                if ((arr[i] & (1 << bit)) && (mx == -1 || arr[i] > arr[mx]))
                    mx = i;
            }

            if (mx == -1) continue;

            swap(arr[index], arr[mx]);

            for (int i = 0; i < n; i++) {
                if (i != index && (arr[i] & (1 << bit)))
                    arr[i] ^= arr[index];
            }

            index++;
        }

        int ans = 0;
        for (int i = 0; i < index; i++)
            ans = max(ans, ans ^ arr[i]);

        return ans;
    }
};

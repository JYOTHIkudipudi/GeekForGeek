class Solution {
public:
    long long findSmallest(vector<int> &arr) {
        
        sort(arr.begin(), arr.end());
        
        long long res = 1;
        
        for(int i = 0; i < arr.size(); i++) {
            
            // If current element is greater than res
            // then res cannot be formed
            if(arr[i] > res)
                break;
            
            // Extend the range
            res += arr[i];
        }
        
        return res;
    }
};

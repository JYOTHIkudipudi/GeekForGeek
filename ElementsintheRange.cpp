class Solution {
  public:
    bool check_elements(int arr[], int n, int start, int end) {
        
        unordered_set<int> s;
        
        // Store all array elements
        for(int i = 0; i < n; i++) {
            s.insert(arr[i]);
        }
        
        // Check every number in range
        for(int i = start; i <= end; i++) {
            if(s.find(i) == s.end()) {
                return false;
            }
        }
        
        return true;
    }
};

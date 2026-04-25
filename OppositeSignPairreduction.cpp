class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
             vector<int> st;

        for (int num : arr) {
            while (!st.empty() && 
                  ((st.back() > 0 && num < 0) || (st.back() < 0 && num > 0))) {

                int top = st.back();

                if (abs(top) > abs(num)) {
                    num = top;     // top survives
                    st.pop_back();
                }
                else if (abs(top) < abs(num)) {
                    st.pop_back(); // current survives, keep checking
                }
                else {
                    st.pop_back(); // both removed
                    num = 0;
                    break;
                }
            }

            if (num != 0) {
                st.push_back(num);
            }
        }

        return st;
    }
};

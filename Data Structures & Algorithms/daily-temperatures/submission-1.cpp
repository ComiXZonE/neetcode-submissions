class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<int> st_idx;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!st_idx.empty()) {
                int idx = st_idx.top();
                st_idx.pop();

                if (temperatures[idx] < temperatures[i]) {
                    result[idx] = i - idx;
                } else {
                    st_idx.push(idx);
                    break;
                }
            }
            st_idx.push(i);
        }

        return result;
    }
};

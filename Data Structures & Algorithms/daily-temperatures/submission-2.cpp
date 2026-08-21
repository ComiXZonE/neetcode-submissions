class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<int> st_idx;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!st_idx.empty() && temperatures[st_idx.top()] < temperatures[i]) {
                int idx = st_idx.top();
                st_idx.pop();
                result[idx] = i - idx;
            }
            st_idx.push(i);
        }

        return result;
    }
};

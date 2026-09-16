class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        stack<tuple<int, int, int>> val_idx;  // val, idx, start
        vector<int> comb;

        sort(candidates.begin(), candidates.end());

        val_idx.push({target, 0, 0});
        while (!val_idx.empty()) {
            auto& [val, idx, start] = val_idx.top();

            // advance past duplicate values at this level, without leaving this iteration
            while (idx < (int)candidates.size() && idx > start &&
                   candidates[idx] == candidates[idx - 1]) {
                idx++;
            }

            if (idx == (int)candidates.size() || val < candidates[idx]) {
                val_idx.pop();
                comb.pop_back();
                continue;
            }

            comb.push_back(candidates[idx]);

            if (val == candidates[idx]) {
                result.push_back(comb);
                comb.pop_back();
            } else {
                val_idx.push({val - candidates[idx], idx + 1, idx + 1});
            }

            idx++;
        }

        return result;
    }
};

class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        // val = remaining target, idx = current candidate being tried, start = idx this frame began
        // at
        stack<tuple<int, int, int>> val_idx;
        vector<int> comb;

        sort(candidates.begin(), candidates.end());

        val_idx.push({target, 0, 0});
        while (!val_idx.empty()) {
            auto& [val, idx, start] = val_idx.top();

            if (idx == candidates.size()) {
                val_idx.pop();
                comb.pop_back();
                continue;
            }

            if (val < candidates[idx]) {
                idx = candidates.size();
                continue;
            }

            if (idx > start && candidates[idx] == candidates[idx - 1]) {
                idx++;  // skip duplicate value at this level
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

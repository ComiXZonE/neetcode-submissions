class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        stack<pair<int, int>> val_idx; // value is the current target, idx is current element being subtracted
        vector<int> comb;

        val_idx.push({target, 0});
        while (!val_idx.empty()) {
            auto& [val, idx] = val_idx.top();

            if (idx == nums.size()) {
                val_idx.pop();
                comb.pop_back();
                continue;
            }

            if (val == nums[idx]) {
                comb.push_back(nums[idx]);
                result.push_back(comb);
                comb.pop_back();
            }
            else if (val > nums[idx]) {
                val_idx.push({val - nums[idx], idx});
                comb.push_back(nums[idx]);
            }
            idx++;
        }

        return result;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diff_idx_map;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (diff_idx_map.find(diff) != diff_idx_map.end())
                return {diff_idx_map[diff], i};

            diff_idx_map[nums[i]] = i;
        }
    }
};

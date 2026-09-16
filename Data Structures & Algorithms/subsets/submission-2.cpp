class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets = {{}};

        for (int i = 0; i < nums.size(); i++) {
            int n = subsets.size();
            for (int j = 0; j < n; j++) {
                vector<int> new_subset = subsets[j];
                new_subset.push_back(nums[i]);
                subsets.push_back(new_subset);
            }
        }

        return subsets;
    }
};

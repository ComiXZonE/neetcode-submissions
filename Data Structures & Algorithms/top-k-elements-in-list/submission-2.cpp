class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;

        for (int num : nums) {
            counts[num]++;
        }

        // kind of an inverse map where frequencies[i] would contain
        // a list of elements that appear i times
        vector<vector<int>> frequencies(nums.size() + 1);

        for (const auto& [num, count] : counts) {
            frequencies[count].push_back(num);
        }

        vector<int> result;
        for (int i = frequencies.size() - 1; i > 0; i--) {
            for (int num : frequencies[i]) {
                result.push_back(num);
                if (--k == 0) {
                    return result;
                }
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;

        for (int num : nums) {
            counts[num]++;
        }

        vector<pair<int, int>> counts_arr(counts.begin(), counts.end());
        sort(counts_arr.begin(), counts_arr.end(), [](const auto& a, const auto& b) {
            return a.second > b.second; 
        });

        vector<int> result;
        for (const auto& pair : counts_arr) {
            result.push_back(pair.first);
            if (--k == 0) {
                break;
            }
        }

        return result;
    }
};

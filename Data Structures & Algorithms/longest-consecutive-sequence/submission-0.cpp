class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        vector<int> seq_starts;

        for (int num : nums) {
            if (nums_set.contains(num - 1))
                continue;

            seq_starts.push_back(num);
        }

        int max_length = 0;

        for (int start : seq_starts) {
            int length = 1;
            while (nums_set.contains(++start)) {
                length++;
            }
            if (length > max_length)
                max_length = length;
        }

        return max_length;
    }
};

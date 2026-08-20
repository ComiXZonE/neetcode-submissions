class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());

        int max_length = 0;
        for (int num : nums) {
            if (nums_set.contains(num - 1))
                continue;

            int length = 1;
            while (nums_set.contains(++num)) {
                length++;
            }
            if (length > max_length)
                max_length = length;
        }

        return max_length;
    }
};

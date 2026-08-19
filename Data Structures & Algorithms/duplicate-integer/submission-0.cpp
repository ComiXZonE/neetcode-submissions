class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> appearance_map;

        for (int& num : nums) {
            if (appearance_map.contains(num))
                return true;
            appearance_map[num] = true;
        }

        return false;
    }
};
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> appearance_set;

        for (int num : nums) {
            if (appearance_set.contains(num))
                return true;
            appearance_set.insert(num);
        }

        return false;
    }
};
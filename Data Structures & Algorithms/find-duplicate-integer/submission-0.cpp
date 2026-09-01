class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set;

        for (int n : nums) {
            if (nums_set.contains(n)) {
                return n;
            }
            nums_set.insert(n);
        }

        return 0;
    }
};

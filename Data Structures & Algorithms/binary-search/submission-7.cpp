class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int i = (left + right) / 2;

            if (target == nums[i]) {
                return i;
            }

            if (target < nums[i]) {
                right = i - 1;
            }
            else {
                left = i + 1;
            }
        }

        return -1;
    }
};

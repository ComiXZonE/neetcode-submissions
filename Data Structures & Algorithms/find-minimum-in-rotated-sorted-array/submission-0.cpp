class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        if (nums[left] < nums[right]) {
            return nums[left];
        }

        while (right - left > 1) {
            int middle = (right + left) / 2;

            if (nums[left] > nums[middle]) {
                right = middle;
            }
            else {
                left = middle;
            }
        }

        return nums[right];
    }
};

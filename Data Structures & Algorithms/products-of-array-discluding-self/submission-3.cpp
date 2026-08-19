class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output = nums;

        int n = nums.size();
        if (n < 2)
            return output;

        vector<int> left(n), right(n);

        left[0] = nums[0];
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i];
        }

        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i];
        }

        output[0] = right[1];
        output[n - 1] = left[n - 2];
        for (int i = 1; i < n - 1; i++) {
            output[i] = left[i - 1] * right[i + 1];
        }

        return output;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size());
        int product = 1;
        int zeros = 0;

        for (int num : nums) {
            if (num != 0)
                product *= num;
            else if (++zeros == 2)
                return output;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (zeros == 1) {
                if (nums[i] != 0)
                    output[i] = 0;
                else
                    output[i] = product;
            }
            else
                output[i] = product / nums[i];
        }

        return output;
    }
};

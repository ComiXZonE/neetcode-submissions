class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        vector<vector<int>> result;
        int i = 0;
        while (true) {
            if (temp[i] > 0) {
                break;
            }

            int j = i + 1, k = temp.size() - 1;

            while (j < k) {
                int sum = temp[i] + temp[j] + temp[k];
                if (sum == 0) {
                    result.push_back({temp[i], temp[j], temp[k]});
                    j++;
                    k--;
                    while (j < k && temp[j] == temp[j - 1]) {
                        j++;
                    }
                }
                else {
                    sum < 0 ? j++ : k--;
                }
            }

            i++;
            while (i < temp.size() && temp[i] == temp[i - 1]) {
                i++;
            }

            if (i == temp.size()) {
                break;
            }
        }

        return result;
    }
};

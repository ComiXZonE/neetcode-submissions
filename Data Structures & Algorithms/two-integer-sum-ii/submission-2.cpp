class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int i = 0;
        int j = numbers.size() - 1;
        int sum = numbers[i] + numbers[j];
        while (sum != target) {
            if (sum < target) {
                i++;
            }
            else {
                j--;
            }
            sum = numbers[i] + numbers[j];
        }

        result.push_back(i + 1);
        result.push_back(j + 1);

        return result;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        int sum = numbers[i] + numbers[j];
        while (sum != target) {
            sum < target ? i++ : j--;
            sum = numbers[i] + numbers[j];
        }

        return {i + 1, j + 1};
    }
};

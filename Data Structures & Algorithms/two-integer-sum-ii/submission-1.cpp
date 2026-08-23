class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // O(n) space solution with the map containing the remainders 
        // when subtracting each of elements from target
        unordered_map<int, int> remainders; // <rem, idx>
        vector<int> result;

        for (int i = 0; i < numbers.size(); i++) {
            remainders[target - numbers[i]] = i;
        }

        for (int i = 0; i < numbers.size(); i++) {
            if (remainders.contains(numbers[i])) {
                if (remainders[numbers[i]] != i) {
                    result.push_back(i + 1);
                    result.push_back(remainders[numbers[i]] + 1);
                    return result;
                }
            }
        }

        return result;
    }
};

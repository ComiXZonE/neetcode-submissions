class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0, i = 0, j = 1;

        while (j < prices.size()) {
            if (prices[i] <= prices[j]) {
                result = max(result, prices[j] - prices[i]);
                j++;
            }
            else {
                i = j;
                j++;
            }
        }

        return result;
    }
};

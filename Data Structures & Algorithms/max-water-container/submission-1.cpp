class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        int l = 0, r = heights.size() - 1;

        while (l < r) {
            result = max(result, (r - l) * min(heights[l], heights[r]));
            heights[l] < heights[r] ? l++ : r--;
        }

        return result;
    }
};

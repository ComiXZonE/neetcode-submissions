class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        int min_height = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (i > 0 && heights[i] <= heights[i - 1]) continue;

            min_height = 10001;
            for (int j = i; j < heights.size(); j++) {
                if (heights[j] == 0) break;

                min_height = min(min_height, heights[j]);
                int rect = (j - i + 1) * min_height;
                result = max(result, rect);
            }
        }

        return result;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> rectangles; // {index, height}
        int n = heights.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (rectangles.empty() || rectangles.top().second <= heights[i]) {
                rectangles.push({i, heights[i]});
                continue;
            }

            pair<int, int> rect;
            while (!rectangles.empty() && rectangles.top().second > heights[i]) {
                rect = rectangles.top();
                result = max(result, (i - rect.first) * rect.second);
                rectangles.pop();
            }

            rectangles.push({rect.first, heights[i]});
        }

        while (!rectangles.empty()) {
            pair<int, int> rect = rectangles.top();
            result = max(result, (n - rect.first) * rect.second);
            rectangles.pop();
        }

        return result;
    }
};

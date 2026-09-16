class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Using lambda to compare elements.
        auto cmp = [](pair<int, int> l, pair<int, int> r) {
            return l.first < r.first; 
        };

        priority_queue<pair<int, int>, std::vector<pair<int, int>>, decltype(cmp)> max_pq(cmp);

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y;

            max_pq.push({dist, i});
            if (max_pq.size() > k) {
                max_pq.pop();
            }
        }

        vector<vector<int>> result;

        while (!max_pq.empty()) {
            auto [dist, idx] = max_pq.top();
            max_pq.pop();
            result.push_back(points[idx]);
        }

        return result;
    }
};

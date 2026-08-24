class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pos_speed(position.size());
        int n = position.size();

        for (int i = 0; i < n; i++) {
            pos_speed.push_back({position[i], speed[i]});
        }
        sort(pos_speed.rbegin(), pos_speed.rend());

        int result = 1;

        double prevTime = (double)(target - pos_speed[0].first) / pos_speed[0].second;
        for (int i = 1; i < n; i++) {
            double currTime = (double)(target - pos_speed[i].first) / pos_speed[i].second;
            if (currTime > prevTime) {
                result++;
                prevTime = currTime;
            }
        }

        return result;
    }
};

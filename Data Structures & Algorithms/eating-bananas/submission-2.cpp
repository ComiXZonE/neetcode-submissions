class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = piles[0];

        for (int pile : piles) {
            right = max(right, pile);
        }

        int prev_k = right;
        int prev_time = 0;
        while (left <= right) {
            int k = (left + right) / 2;
            int time = hoursNeeded(piles, k);

            if (time > h) {
                left = k + 1;
            }
            else {
                if (time >= prev_time) {
                    prev_time = time;
                    prev_k = k;
                }
                right = k - 1;
            }
        }

        return prev_k;
    }

    int hoursNeeded(vector<int>& piles, int k) {
        int result = 0;
        for (int pile : piles) {
            result += (pile / k) + (pile % k != 0);
        }

        return result;
    }
};

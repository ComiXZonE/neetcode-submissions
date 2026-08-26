class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = piles[0];

        for (int pile : piles) {
            right = max(right, pile);
        }

        int result = right;
        while (left <= right) {
            int k = (left + right) / 2;
            int time = hoursNeeded(piles, k);

            if (time > h) {
                left = k + 1;
            }
            else {
                result = k;
                right = k - 1;
            }
        }

        return result;
    }

    int hoursNeeded(vector<int>& piles, int k) {
        int result = 0;
        for (int pile : piles) {
            result += (pile / k) + (pile % k != 0);
        }

        return result;
    }
};

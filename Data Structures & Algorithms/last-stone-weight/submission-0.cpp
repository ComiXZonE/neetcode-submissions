class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_prio_q;

        for (int num : stones) {
            max_prio_q.push(num);
        }

        while (max_prio_q.size() > 1) {
            int s1 = max_prio_q.top();
            max_prio_q.pop();
            int s2 = max_prio_q.top();
            max_prio_q.pop();

            if (s1 == s2) continue;

            max_prio_q.push(abs(s1 - s2));
        }

        if (!max_prio_q.empty())
            return max_prio_q.top();

        return 0;
    }
};

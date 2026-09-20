class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task_count(26, 0);

        auto comp = [&task_count](int l, int r) { return task_count[l] < task_count[r]; };
        priority_queue<int, vector<int>, decltype(comp)> task_next(comp);

        queue<pair<int, int>> task_blocked_until;

        int result = 0;

        for (char task : tasks) {
            task_count[task - 'A']++;
        }

        for (int i = 0; i < task_count.size(); i++) {
            if (task_count[i] > 0)
                task_next.push(i);
        }

        int scheduled_cnt = 0;
        while (scheduled_cnt < tasks.size()) {
            if (!task_blocked_until.empty()) {
                auto [task, cycle] = task_blocked_until.front();
                if (result == cycle) {
                    task_next.push(task);
                    task_blocked_until.pop();
                }
            }

            if (!task_next.empty()) {
                int task = task_next.top();
                task_next.pop(); 
                scheduled_cnt++;

                if (--task_count[task] > 0) {
                    task_blocked_until.push({task, result + n + 1});
                }
            }
            
            result++;
        }

        return result;
    }
};

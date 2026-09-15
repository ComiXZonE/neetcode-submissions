class KthLargest {
   public:
    KthLargest(int k, vector<int>& nums) : k_(k) {
        for (int num : nums) {
            min_priority_queue_.push(num);
            if (min_priority_queue_.size() > k_) {
                min_priority_queue_.pop();
            }
        }
    }

    int add(int val) {
        min_priority_queue_.push(val);
        if (min_priority_queue_.size() > k_) {
            min_priority_queue_.pop();
        }

        return min_priority_queue_.top();
    }

   private:
    priority_queue<int, vector<int>, greater<int>> min_priority_queue_;
    int k_;
};

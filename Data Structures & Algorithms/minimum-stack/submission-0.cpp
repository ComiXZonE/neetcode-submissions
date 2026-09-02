class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        if (stack_.empty() || val < stack_.top().second) {
            stack_.push({val, val});
        }
        else {
            stack_.push({val, stack_.top().second});
        }
    }
    
    void pop() {
        stack_.pop();
    }
    
    int top() {
        return stack_.top().first;
    }
    
    int getMin() {
        return stack_.top().second;
    }

private:
    stack<pair<int, int>> stack_;
};

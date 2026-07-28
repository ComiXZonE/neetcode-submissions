class LinkedList {
   public:
    LinkedList() : tail_(nullptr), size_(0) {}

    int get(int index) {
        if (index >= size_) return -1;

        Node* curr = head_.get();
        for (int i = 0; i < index; i++) {
            curr = curr->next_.get();
        }

        return curr->value_;
    }

    void insertHead(int val) {
        auto node = std::make_unique<Node>(val);

        if (size_ == 0) {
            tail_ = node.get();
        } else {
            node->next_ = std::move(head_);
        }

        head_ = std::move(node);
        ++size_;
    }

    void insertTail(int val) {
        auto node = std::make_unique<Node>(val);
        Node* newTail = node.get(); // have to save newTail because node.get() won't work later when it gets moved

        if (size_ == 0) {
            head_ = std::move(node);
        } else {
            tail_->next_ = std::move(node);
        }

        tail_ = newTail;
        ++size_;
    }

    bool remove(int index) {
        if (index >= size_) return false;

        if (index == 0) {
            head_ = std::move(head_->next_);
            if (size_ == 1) {
                tail_ = nullptr;
            }
            --size_;
            return true;
        }

        Node* curr = head_.get();
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next_.get();
        }

        std::unique_ptr<Node>& target = curr->next_;
        if (target.get() == tail_) {
            tail_ = curr;
        }

        curr->next_ = std::move(target->next_);
        --size_;
        return true;
    }

    vector<int> getValues() {
        vector<int> result;
        Node* curr = head_.get();
        for (int i = 0; i < size_; i++) {
            result.push_back(curr->value_);
            curr = curr->next_.get();
        }
        return result;
    }

   private:
    struct Node {
        int value_;
        unique_ptr<Node> next_;

        Node(int val) : value_(val), next_(nullptr) {}
    };

    unique_ptr<Node> head_;
    Node* tail_;
    int size_;
};

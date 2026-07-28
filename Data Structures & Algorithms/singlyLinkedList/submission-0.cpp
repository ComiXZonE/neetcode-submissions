class LinkedList {
public:
    LinkedList() 
    : head_(nullptr), 
      tail_(nullptr),
      size_(0)
    {
    }

    int get(int index) {
        if (index >= size_)
            return -1;

        Node* curr = head_;
        for (int i = 0; i < index; i++) {
            curr = curr->next_;
        }

        return curr->value_;
    }

    void insertHead(int val) {
        Node* node = new Node(val);

        if (size_ == 0) {
            head_ = tail_ = node;
        }
        else {
            node->next_ = head_;
            head_ = node;
        }

        ++size_;
    }
    
    void insertTail(int val) {
        Node* node = new Node(val);

        if (size_ == 0) {
            head_ = tail_ = node;
        }
        else {
            tail_->next_ = node;
            tail_ = node;
        }

        ++size_;
    }

    bool remove(int index) {
        if (index >= size_)
            return false;

        Node* to_remove;

        if (size_ == 1) {
            to_remove = head_;
            head_ = tail_ = nullptr;
        }
        else {
            Node* curr = head_;
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next_;
            }

            to_remove = (index == 0) ? head_ : curr->next_;

            if (to_remove == head_) {
                head_ = to_remove->next_;
            }
            else if (to_remove == tail_) {
                tail_ = curr;
                tail_->next_ = nullptr;
            }
            else {
                curr->next_ = to_remove->next_;
            }
        }

        to_remove->next_ = nullptr;
        delete to_remove;
        --size_;
        return true;
    }

    vector<int> getValues() {
        vector<int> result;
        Node* curr = head_;
        for (int i = 0; i < size_; i++) {
            result.push_back(curr->value_);
            curr = curr->next_;
        }
        return result;
    }

private:
    struct Node {
        int value_;
        Node* next_;

        Node(int val)
        : value_(val), next_(nullptr)
        {}
    };

    Node* head_;
    Node* tail_;
    int size_;
};

struct LRUCacheLine {
    int val = 0;
    int key = 0;
    LRUCacheLine* next = nullptr;
    LRUCacheLine* prev = nullptr;

    LRUCacheLine(int key, int value) : key(key), val(value), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : head_(nullptr), tail_(nullptr), size_(0), capacity_(capacity) {}

    int get(int key) {
        if (key_line_.contains(key)) {
            LRUCacheLine* line = key_line_[key];
            remove(line);
            insert(line);
            return line->val;
        }

        return -1;
    }

    void put(int key, int value) {
        if (key_line_.contains(key)) {
            LRUCacheLine* line = key_line_[key];
            line->val = value;
            remove(line);
            insert(line);
        } else if (size_ < capacity_) {
            LRUCacheLine* line = new LRUCacheLine(key, value);
            insert(line);
            key_line_[key] = line;
            size_++;
        } else {
            LRUCacheLine* line = new LRUCacheLine(key, value);
            LRUCacheLine* removed_line = remove(tail_);
            key_line_.erase(removed_line->key);
            delete removed_line;
            insert(line);
            key_line_[key] = line;
        }
    }

private:
    LRUCacheLine* remove(LRUCacheLine* line) {
        if (line == nullptr) 
            return nullptr;

        // Fix the previous node's next pointer (or update head)
        if (line->prev != nullptr) {
            line->prev->next = line->next;
        } else {
            head_ = line->next;
        }

        // Fix the next node's prev pointer (or update tail)
        if (line->next != nullptr) {
            line->next->prev = line->prev;
        } else {
            tail_ = line->prev;
        }

        // Detach node from the list (optional, but good hygiene)
        line->prev = nullptr;
        line->next = nullptr;

        return line;
    }

    void insert(LRUCacheLine* line) {
        line->prev = nullptr;
        line->next = head_;

        if (head_ != nullptr) {
            head_->prev = line;
        } else {
            // List was empty, so the new node is also the tail
            tail_ = line;
        }

        head_ = line;
    }

    unordered_map<int, LRUCacheLine*> key_line_;
    LRUCacheLine* head_;
    LRUCacheLine* tail_;
    int capacity_;
    int size_;
};

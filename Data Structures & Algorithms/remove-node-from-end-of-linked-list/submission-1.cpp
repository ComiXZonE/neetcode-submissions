/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        while (first != nullptr && n >= 0) {
            first = first->next;
            n--;
        }

        if (first == nullptr && n == 0) {
            ListNode* node = head->next;
            delete head;
            return node;
        }

        ListNode* second = head;
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        ListNode* node = second->next;

        if (node == head) {
            head = head->next;
        } else if (node->next == nullptr) {
            second->next = nullptr;
        } else {
            second->next = node->next;
        }

        delete node;

        return head;
    }
};

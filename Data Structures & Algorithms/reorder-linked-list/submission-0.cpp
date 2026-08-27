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
    void reorderList(ListNode* head) {
        int length = 0;

        for (ListNode* node = head; node != nullptr; node = node->next) {
            length++;
        }

        ListNode* node = head;

        for (int i = 0; i < length / 2; i++) {
            node = node->next;
        }

        ListNode* temp = node;
        node = node->next;
        temp->next = nullptr;

        ListNode* rev_head = nullptr;

        while (node != nullptr) {
            if (rev_head == nullptr) {
                rev_head = node;
                node = node->next;
                rev_head->next = nullptr;
            }
            else {
                ListNode* temp = node->next;
                node->next = rev_head;
                rev_head = node;
                node = temp;
            }
        }

        node = head;
        ListNode* rev_node = rev_head;
        int turn = 1;

        while (node != nullptr && rev_node != nullptr) {
            if (turn == 1) {
                ListNode* temp = node->next;
                node->next = rev_node;
                node = temp;
            }
            else {
                ListNode* temp = rev_node->next;
                rev_node->next = node;
                rev_node = temp;
            }
            turn *= -1;
        }
    }
};

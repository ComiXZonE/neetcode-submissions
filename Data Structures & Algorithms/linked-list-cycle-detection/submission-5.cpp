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
    bool hasCycle(ListNode* head) {
        ListNode* faster = head;
        ListNode* slower = head;

        while (faster != nullptr && faster->next != nullptr) {
            faster = faster->next->next;
            slower = slower->next;

            if (faster == slower) {
                return true;
            }
        }

        return false;
    }
};

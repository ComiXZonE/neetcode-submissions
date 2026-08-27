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
        if (head == nullptr) {
            return false;
        }
        
        ListNode* faster = head;
        ListNode* slower = head;

        do {
            faster = faster->next;
            if (faster == nullptr) {
                break;
            }
            faster = faster->next;
            slower = slower->next;
        } while (faster != nullptr && faster != slower);

        return (faster == slower);
    }
};

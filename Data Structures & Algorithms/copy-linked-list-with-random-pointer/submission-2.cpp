/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldToNew;

        Node* node = head;
        while (node != nullptr) {
            Node* new_node = new Node(node->val);
            oldToNew[node] = new_node;
            node = node->next;
        }

        node = head;
        while (node != nullptr) {
            oldToNew[node]->next = oldToNew[node->next];
            oldToNew[node]->random = oldToNew[node->random];
            node = node->next;
        }

        return oldToNew[head];
    }
};

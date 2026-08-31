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
        unordered_map<Node*, vector<Node*>> nodes;
        unordered_map<Node*, int> node_idx;
        vector<Node*> new_nodes;

        Node* node = head;
        Node* new_head = nullptr;
        Node* new_tail = nullptr;
        int i = 0;
        while (node != nullptr) {
            Node* new_node = new Node(node->val);
            if (new_head == nullptr) {
                new_head = new_node;
                new_tail = new_node;
            } else {
                new_tail->next = new_node;
                new_tail = new_node;
            }

            nodes[node->random].push_back(node);
            node_idx[node] = i++;
            new_nodes.push_back(new_node);
            node = node->next;
        }

        node = head;
        Node* new_node = new_head;
        while (node != nullptr) {
            for (Node* n : nodes[node]) {
                int idx = node_idx[n];
                new_nodes[idx]->random = new_node;
            }
            node = node->next;
            new_node = new_node->next;
        }

        return new_head;
    }
};

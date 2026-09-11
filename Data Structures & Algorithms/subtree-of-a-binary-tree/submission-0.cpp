/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> candidates;
        stack<TreeNode*> to_visit;

        to_visit.push(root);

        while (!to_visit.empty()) {
            TreeNode* node = to_visit.top();
            to_visit.pop();

            if (!node) continue;

            if (node->val == subRoot->val) {
                candidates.push(node);
            }

            to_visit.push(node->left);
            to_visit.push(node->right);
        }

        while (!candidates.empty()) {
            stack<pair<TreeNode*, TreeNode*>> comparison;
            TreeNode* candidate_root = candidates.front();
            candidates.pop();

            comparison.push({candidate_root, subRoot});

            bool match = true;
            while (!comparison.empty()) {
                auto [node1, node2] = comparison.top();
                comparison.pop();

                if (!node1 && !node2) continue;

                if (!node1 || !node2 || node1->val != node2->val) {
                    match = false;
                    break;
                }

                comparison.push({node1->left, node2->left});
                comparison.push({node1->right, node2->right});
            }

            if (match) return true;
        }

        return false;

    }
};

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> p_stack;
        stack<TreeNode*> q_stack;

        p_stack.push(p);
        q_stack.push(q);

        while (!p_stack.empty() && !q_stack.empty()) {
            TreeNode* p_node;
            TreeNode* q_node;

            if (!p_stack.empty()) {
                p_node = p_stack.top();
                p_stack.pop();
            } else {
                p_node = nullptr;
            }

            if (!q_stack.empty()) {
                q_node = q_stack.top();
                q_stack.pop();
            } else {
                q_node = nullptr;
            }

            if (p_node && !q_node || !p_node && q_node) return false;

            if (p_node && q_node && p_node->val != q_node->val) return false;

            if (!p_node && !q_node) continue;

            if (p_node && q_node) {
                p_stack.push(p_node->left);
                p_stack.push(p_node->right);
                q_stack.push(q_node->left);
                q_stack.push(q_node->right);
            }
        }

        return true;
    }
};

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> to_visit;

        int min_val = min(p->val, q->val);
        int max_val = max(p->val, q->val);

        to_visit.push(root);

        while (!to_visit.empty()) {
            TreeNode* node = to_visit.top();
            to_visit.pop();

            if (node->val >= min_val && node->val <= max_val) return node;

            if (node->val < min_val) to_visit.push(node->right);
            if (node->val > max_val) to_visit.push(node->left);
        }

        return nullptr;
    }
};

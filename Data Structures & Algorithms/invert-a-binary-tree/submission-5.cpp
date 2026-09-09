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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;

        stack<TreeNode*> nodes_to_invert;
        nodes_to_invert.push(root);

        while (!nodes_to_invert.empty()) {
            TreeNode* node = nodes_to_invert.top();
            nodes_to_invert.pop();
            if (node->left != nullptr) {
                nodes_to_invert.push(node->left);
            }
            if (node->right != nullptr) {
                nodes_to_invert.push(node->right);
            }
            swap(node->left, node->right);
        }

        return root;
    }
};

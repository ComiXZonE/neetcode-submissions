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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> val_idx;

        for (int i = 0; i < inorder.size(); i++) {
            val_idx[inorder[i]] = i;
        }

        stack<tuple<TreeNode*, pair<int, int>, pair<int, int>>> node_subtree_boundaries;

        TreeNode* root = new TreeNode(preorder[0]);
        int root_inorder_idx = val_idx[root->val];
        node_subtree_boundaries.push(
            {root, {0, root_inorder_idx - 1}, {root_inorder_idx + 1, inorder.size() - 1}});

        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* node = new TreeNode(preorder[i]);
            int node_inorder_idx = val_idx[node->val];
            auto& [parent, left_subtree, right_subtree] = node_subtree_boundaries.top();
            auto& [left_low, left_high] = left_subtree;
            auto& [right_low, right_high] = right_subtree;

            if (node_inorder_idx >= left_low && node_inorder_idx <= left_high) {
                parent->left = node;
                node_subtree_boundaries.push(
                    {node, {left_low, node_inorder_idx - 1}, {node_inorder_idx + 1, left_high}});
                left_low = 0;
                left_high = -1;
            } else {
                parent->right = node;
                node_subtree_boundaries.push(
                    {node, {right_low, node_inorder_idx - 1}, {node_inorder_idx + 1, right_high}});
                right_low = 0;
                right_high = -1;
            }

            {
                while (!node_subtree_boundaries.empty()) {
                    auto& [node, left_subtree, right_subtree] = node_subtree_boundaries.top();
                    auto& [left_low, left_high] = left_subtree;
                    auto& [right_low, right_high] = right_subtree;

                    if (left_low > left_high && right_low > right_high) {
                        node_subtree_boundaries.pop();
                    } else {
                        break;
                    }
                }
            }
        }

        return root;
    }
};

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int result = 0;

        stack<pair<TreeNode*, int>> node_depth;
        node_depth.push({root, 1});

        while (!node_depth.empty()) {
            auto [node, depth] = node_depth.top();
            node_depth.pop();

            if (node->left != nullptr) {
                node_depth.push({node->left, depth + 1});
            }

            if (node->right != nullptr) {
                node_depth.push({node->right, depth + 1});
            }

            result = max(result, depth);
        }

        return result;
    }
};

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

        stack<pair<TreeNode*, int>> node_height;
        node_height.push({root, 1});

        while (!node_height.empty()) {
            auto [node, height] = node_height.top();
            node_height.pop();

            if (node->left != nullptr) {
                node_height.push({node->left, height + 1});
            }

            if (node->right != nullptr) {
                node_height.push({node->right, height + 1});
            }

            result = max(result, height);
        }

        return result;
    }
};

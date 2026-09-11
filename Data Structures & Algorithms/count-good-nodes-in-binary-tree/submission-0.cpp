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
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<pair<TreeNode*, int>> node_max;
        int result = 0;

        node_max.push({root, root->val});

        while (!node_max.empty()) {
            auto [node, max] = node_max.front();
            node_max.pop();
            
            if (node->val >= max) {
                result++;
                max = node->val;
            }

            if (node->left) node_max.push({node->left, max});
            if (node->right) node_max.push({node->right, max});
        }

        return result;
    }
};

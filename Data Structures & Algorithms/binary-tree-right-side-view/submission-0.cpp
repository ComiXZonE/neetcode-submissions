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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<pair<TreeNode*, int>> node_level;

        node_level.push({root, 0});

        while (!node_level.empty()) {
            auto [node, level] = node_level.front();
            node_level.pop();

            if (node == nullptr) continue;

            if (result.size() == level) {
                result.push_back(node->val);
            }
            else {
                result[level] = node->val;
            }

            node_level.push({node->left, level + 1});
            node_level.push({node->right, level + 1});            
        }

        return result;
    }
};

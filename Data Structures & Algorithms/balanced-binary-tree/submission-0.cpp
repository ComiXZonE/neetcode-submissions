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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        stack<pair<TreeNode*, bool>> node_visit;
        unordered_map<TreeNode*, int> node_height;

        node_visit.push({root, false});

        while (!node_visit.empty()) {
            auto [node, visited] = node_visit.top();
            node_visit.pop();

            if (!visited) {
                node_visit.push({node, true});
                if (node->left) node_visit.push({node->left, false});
                if (node->right) node_visit.push({node->right, false});
            }
            else {
                if (abs(node_height[node->left] - node_height[node->right]) > 1)
                    return false;

                node_height[node] = max(node_height[node->left], node_height[node->right]) + 1;
            }
        }

        return true; 
    }
};

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
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, int> height;   // node -> height of subtree
        stack<pair<TreeNode*, bool>> to_visit;  // <node, visited?>
        to_visit.push({root, false});
        int result = 0;

        while (!to_visit.empty()) {
            auto [node, visited] = to_visit.top();
            to_visit.pop();
            if (!node) continue;

            if (visited) {
                int l = node->left ? height[node->left] : 0;
                int r = node->right ? height[node->right] : 0;
                height[node] = 1 + max(l, r);
                result = max(result, l + r);
            } else {
                to_visit.push({node, true});  // re-push as "visited" for later
                to_visit.push({node->left, false});
                to_visit.push({node->right, false});
            }
        }

        return result;
    }
};

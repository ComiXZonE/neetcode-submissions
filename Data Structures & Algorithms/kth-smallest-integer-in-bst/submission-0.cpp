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
    int kthSmallest(TreeNode* root, int k) {
        stack<pair<TreeNode*, bool>> to_visit;

        to_visit.push({root, false});

        while (!to_visit.empty()) {
            auto [node, visited] = to_visit.top();
            to_visit.pop();

            if (node == nullptr) continue;

            if (!visited) {
                to_visit.push({node->right, false});
                to_visit.push({node, true});
                to_visit.push({node->left, false});
            } else if (--k == 0) {
                return node->val;
            }
        }
    }
};

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
        max_diameter = 0;
        treeHeightWithDiameterUpdate(root);
        return max_diameter;
    }

private:
    int treeHeightWithDiameterUpdate(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftSubtreeHeight = treeHeightWithDiameterUpdate(root->left);
        int rightSubtreeHeight = treeHeightWithDiameterUpdate(root->right);

        int diameter = leftSubtreeHeight + rightSubtreeHeight;

        if (diameter > max_diameter)
            max_diameter = diameter;

        return 1 + max(leftSubtreeHeight, rightSubtreeHeight);
    }

    int max_diameter = 0;
};

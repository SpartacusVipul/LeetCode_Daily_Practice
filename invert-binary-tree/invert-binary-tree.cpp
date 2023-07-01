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
    // make left point to right subtree
    // make right point to left subtree
    // make a recursive call to update the left and right inside the subtrees
    // return root
    TreeNode* invertHelper(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = right;
        root->right = left;
        invertHelper(root->left);
        invertHelper(root->right);
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        return invertHelper(root);
    }
};
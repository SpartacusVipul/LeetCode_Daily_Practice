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
    bool preorder(TreeNode *root, int target) {
        if (root == NULL) return false;
        
        if (root->left == NULL && root->right == NULL) return target - root->val == 0; 
        if (preorder(root->left, target - root->val)) return true;
        if (preorder(root->right, target - root->val)) return  true;
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        // if (root == NULL ) return false;
        return preorder(root, targetSum);
    }
};
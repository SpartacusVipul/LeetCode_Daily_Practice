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
    int totalSum = 0;
    void preorder(TreeNode* root, int currentSum) {
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL) {
            totalSum += (currentSum * 10) + root->val;
            return;
        } 
        preorder(root->left, (currentSum * 10) + root->val);
        preorder(root->right, (currentSum * 10) + root->val);

    }

    int sumNumbers(TreeNode* root) {
        preorder(root, 0);
        return totalSum;
    }
};
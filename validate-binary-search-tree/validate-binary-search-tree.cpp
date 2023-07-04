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
    TreeNode *prevNode = NULL;
    // very similar to other problem, minimum absolute difference
    // in inorder traversal, we should get a sorted array,
    // so, if at any time prevNode val is greater than root val, then not sorted, so not BST 
    // prevNode is updated whenever we print the node in regular inorder traversal
    bool inorder(TreeNode *root) {
        if (root == NULL) {
            return true;
        }

        bool val = false;
        val = inorder(root->left);
        if (val == false) return false;
        if (prevNode != NULL && root->val <= prevNode->val) {
            return false;
        }
        prevNode = root;
        val = inorder(root->right);
        if (val == false) return false;
        return true;
    }   

    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};
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
    // getLeftHeight to find height from current root to left most node 
    // getRightHeight is find height from current root to rightmost node 
    // since it is a complete binary tree, expect last level, all other levels 
    // are fully filled, and last level is left most fully filled 
    // with this idea, for every node, we check left most height and rightmoist height for it 
    // if left most height is same as rightmost height, then complete biunary tree so 
    // number of nodes is equal to ((2^h) - 1). 
    // if left and right are not equal, then we recursively check in left and right 
    // go to left node, find its left and right heights, and if equal same formula as above,
    // if not go to left and right childs, 
    // this is continued till a NULL or same height is encountered
    // idea is we get left and right number of nodes in the recurisve calls and add 1 (current node) and return when 
    // there is height difference 
    int getLeftHeight(TreeNode *root) {
        int height = 1;
        while (root != NULL) {
            root = root->left;
            height ++;
        }
        return height;
    }
    
    int getRightHeight(TreeNode *root) {
        int height = 1;
        while (root != NULL) {
            root = root->right;
            height ++;
        }
        return height;
    }
    
    int traverse(TreeNode *root) {
        if (root == NULL) return 0;

        int leftHeight = getLeftHeight(root->left);
        int rightHeight = getRightHeight(root->right);
        if (leftHeight == rightHeight) {
            return max((int)pow(2, leftHeight) - 1, 1);
        }

        return traverse(root->left) + 1 + traverse(root->right);
    }

    int countNodes(TreeNode* root) {
        return traverse(root);
    }
};
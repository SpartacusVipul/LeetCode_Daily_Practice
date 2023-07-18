class Solution {
public:
    TreeNode* flattenHelper(TreeNode* root) {
        if (root == NULL) return NULL;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        TreeNode *leftTail = flattenHelper(left);
        TreeNode *rightTail = flattenHelper(right);

        if (left) {
            root->left = NULL;
            root->right = left;
            if (leftTail != NULL) {
                leftTail->left = NULL;
                leftTail->right = right;
            } else {
                left->left = NULL;
                left->right = right;
            }            
        }
        
        if (leftTail == NULL && rightTail == NULL) return root;
        if (leftTail != NULL && rightTail == NULL) return leftTail;
        return rightTail;
    }

    void flatten(TreeNode* root) {
        flattenHelper(root);
    }
};
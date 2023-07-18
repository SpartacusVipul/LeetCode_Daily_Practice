class Solution {
public:
    // basic idea is use traversal 
    // flatten left, flatten right 
    // the flatten should return the last node in the flatten part i.e the tail 
    // now, assume there is not left subtree, and only a right subtree,
    // in that case, root->left is already null and root->right still points to root of right subtree
    // now, since we have already called flatten on right subtree, it returns right subtree's tail 
    // since there is no left, we just have to return right subtree tail
    // assume there is only left and no right, 
    // in this case, we make root->left equal to NULL, root->right to left 
    // but left can have single node or its own subtree,
    // when left is single node, leftTail will be same as the left node 
    // if not lefttail is the last node in flatten part 
    // in both cases, leftTail->left = NULL and leftTail->right = right 
    // finally we need to return tail of this subtree, 
    // if left and right are null, return root
    // if left is null and right is not null, return right tail 
    // if left is not null and right is null, return left tail  
    TreeNode* flattenHelper(TreeNode* root) {
        if (root == NULL) return NULL;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        TreeNode *leftTail = flattenHelper(left);
        TreeNode *rightTail = flattenHelper(right);

        if (left) {
            root->left = NULL;
            root->right = left;
            leftTail->left = NULL;
            leftTail->right = right;        
        }
        
        if (leftTail == NULL && rightTail == NULL) return root;
        if (leftTail != NULL && rightTail == NULL) return leftTail;
        return rightTail;
    }

    void flatten(TreeNode* root) {
        flattenHelper(root);
    }
};
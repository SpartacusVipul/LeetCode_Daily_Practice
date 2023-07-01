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
    bool checkSame(TreeNode* r1, TreeNode* r2) {
        if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL))
        {
            return false;
        }
        if (r1== NULL && r2 == NULL) {
            return true;
        } 
        if (r1 ->val != r2->val) {
            return false;
        }
        if (checkSame(r1->left, r2->left) == false)
            return false;
        
        if (checkSame(r1->right, r2->right) == false)
            return false;
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkSame(p, q);
    }
};
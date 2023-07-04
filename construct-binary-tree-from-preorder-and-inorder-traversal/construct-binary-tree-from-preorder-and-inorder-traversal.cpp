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
    // tricky problem, complexity is somewhat reduced in python
    // in preorder first node is root,
    // this is assuming each value is unique in the preorder and post order
    // so, find the first node from preorder in the inorder
    // once found, that node is mid,
    // divide preorder and inorder based on this mid
    // in inorder, everything on left of mid is the left subtree for mid node 
    // everything on right of mid is right subtree for mid node
    // so, partition inorder based on mid node two halves, inStart to mid, mid+ 1 to inEnd (the end nodes are not included)
    // similarly partition preorder 
    // preStart + 1, mid + 1 is left subtree and mid + 1 to preEnd is right subtree
    // call recursive functions with above parameters 
    TreeNode *buildHelper(int preStart, int preEnd, int inStart, int inEnd, 
                      vector<int>& preorder, vector<int>& inorder) {
        if (preStart > preEnd || inStart >= inEnd) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preStart]);
        int mid = -1;
        for (int i = inStart; i < inEnd; i++) {
            if (inorder[i] == preorder[preStart]) {
                mid = i;
                break;
            }
        }
        if (mid == -1) {
            return NULL;
        }
        root->left = buildHelper(preStart + 1, preStart + (mid - inStart) + 1, inStart, mid, preorder, inorder);
        root->right = buildHelper(preStart + (mid - inStart) + 1, preEnd, mid + 1, inEnd, preorder, inorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildHelper(0, preorder.size(), 0, inorder.size(), preorder, inorder);
    }
};
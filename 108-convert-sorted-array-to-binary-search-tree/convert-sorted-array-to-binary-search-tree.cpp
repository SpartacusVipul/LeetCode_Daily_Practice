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
    // since we are given a sorted array, and we want to build a balanced binary tree out of it 
    // every time the mid element of the array becomes the root, 
    // the left half goes to left subtree, the right half goes to right subtree

    TreeNode *buildHelper(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;

        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildHelper(nums, left, mid - 1);
        root->right = buildHelper(nums, mid + 1, right);
        return root;
    }


    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        return buildHelper(nums, left, right);
    }
};
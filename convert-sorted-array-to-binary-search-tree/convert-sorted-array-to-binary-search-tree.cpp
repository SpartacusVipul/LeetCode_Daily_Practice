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
    // basic idea is using divide and conquer, create a new node with mid
    // left subtree will be from start to mid - 1
    // right subtree from mid + 1 to end
    // Note some base cases, where if start is equal to nums.size(), return NULL,
    // or start > end return NULL, 
    TreeNode *buildTreeHelper(int start, int end, vector<int> &nums) {
        if (start > end || start == nums.size()) return NULL;
        if (start == end) return new TreeNode(nums[start]);

        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildTreeHelper(start, mid - 1, nums);
        root->right = buildTreeHelper(mid + 1, end, nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = buildTreeHelper(0, nums.size(), nums);
        return root;
    }
};
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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> resVec;
        if (root == NULL) {
            return resVec;
        }
        deque<TreeNode *> levelQ;
        levelQ.push_back(root);
        int orderFlag = 0;
        while (!levelQ.empty()) {
            int size = levelQ.size();
            vector<int> levelVec;
            while (size --) {
                TreeNode *curr;
                if (orderFlag == 1) {
                    curr = levelQ.front();
                    levelQ.pop_front();
                } else {
                    curr = levelQ.back();
                    levelQ.pop_back();
                }
                
                levelVec.push_back(curr->val);
                if (orderFlag == 1) {
                    if (curr->right != NULL) levelQ.push_back(curr->right);
                    if (curr->left != NULL) levelQ.push_back(curr->left);
                } else {
                    if (curr->left != NULL) levelQ.push_front(curr->left);
                    if (curr->right != NULL) levelQ.push_front(curr->right);
                }
            }
            resVec.push_back(levelVec);
            orderFlag = orderFlag == 1 ? 0 : 1;
        }
        return resVec;
    }
};
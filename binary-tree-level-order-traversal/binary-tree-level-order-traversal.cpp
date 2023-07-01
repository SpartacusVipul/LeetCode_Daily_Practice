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
    // small trick in the second while loop
    // finding the queue size and removign all the elements of qsize from the queue from front,
    // while simultaneously inserting new elements into the queue at back
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> resVec;
        queue<TreeNode*> levelQ;
        if (root != NULL)
            levelQ.push(root);
        while (!levelQ.empty()) {
            int qSize = levelQ.size();
            vector<int> levelVec;
            while (qSize -- ) {
                TreeNode* temp = levelQ.front();
                levelVec.push_back(temp->val);
                if (temp->left != NULL) {
                    levelQ.push(temp->left);
                }
                if (temp->right != NULL) {
                    levelQ.push(temp->right);
                }
                levelQ.pop();
            }
            resVec.push_back(levelVec);
        }
        return resVec;
    }
};
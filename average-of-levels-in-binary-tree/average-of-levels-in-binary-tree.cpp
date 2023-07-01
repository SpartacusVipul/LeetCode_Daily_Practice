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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> levelVector;
        vector<double> resVec;
        levelVector.push(root);
        while (!levelVector.empty()) {
            double sum = 0, size = levelVector.size(), sizeCopy = levelVector.size();
            while (size--) {
                TreeNode* temp = levelVector.front();
                sum += temp->val;
                if (temp->left != NULL)
                    levelVector.push(temp->left);
                if (temp->right != NULL)
                    levelVector.push(temp->right);
                levelVector.pop();
            }
            resVec.push_back(sum / sizeCopy);
        }
        return resVec;
    }
};
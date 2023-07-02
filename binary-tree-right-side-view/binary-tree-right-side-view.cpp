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
    vector<int> rightSideView(TreeNode* root) {
        
        queue<TreeNode*> levelQ;
        levelQ.push(root);
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        // have two queues, levelQ and currentQ,
        //initially inbsert root to levelQ
        while (!levelQ.empty()) {
            //copy contents of levelQ to currentQ
            queue<TreeNode*> currentLevel;
            while (!levelQ.empty()) {
                currentLevel.push(levelQ.front());
                levelQ.pop();
            }
            // in the current Q, the front element will be the rightmost element as we are inserting right first then left
            res.push_back(currentLevel.front()->val);
            //in the currentQ, check all its children and insert them into levelQ
            while (!currentLevel.empty()) {
                TreeNode* element = currentLevel.front();
                currentLevel.pop();   
                if (element->right != NULL) {
                    levelQ.push(element->right);
                } 
                if (element->left != NULL) {
                    levelQ.push(element->left);
                }
            }
        }
        return res;
    }
};
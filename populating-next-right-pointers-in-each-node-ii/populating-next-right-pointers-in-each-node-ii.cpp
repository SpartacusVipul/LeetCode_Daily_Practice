/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // trick is using a temp node, at the start for each level,
    // some memory wastage, but overall, doesnt affect anything else
    // just make temp->next equal to node, update temp to node
    // finally set temp next to NULL 
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        queue<Node*> levelQ;
        levelQ.push(root);
        while (!levelQ.empty()) {
            int qSize = levelQ.size();
            Node *temp = new Node(0);
            while (qSize --) {
                Node *node = levelQ.front();
                levelQ.pop();
                if (node && node->left) levelQ.push(node->left);
                if (node && node->right) levelQ.push(node->right);
                temp->next = node;
                temp = node;
            }
            temp->next = NULL;
        }
        return root;
    }
};
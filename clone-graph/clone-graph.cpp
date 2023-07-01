/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // trick is hacing a visited array of nodes and 
    // for making a copy node for every node and recursively adding neighbours to it
    // for every node, we create a copy node 
    // and for all the neighbours, we push back all the new neighbours into 
    // the copyNodes neighbour vector
    // recursivley proceed
    Node *cloneHelper(Node *node, vector<Node *> &visited) {
        if (node == NULL) {
            return  NULL;
        }
        if (visited[node->val] != NULL) {
            return visited[node->val];
        }

        Node *copyNode = new Node(node->val);
        visited[copyNode->val] = copyNode; 
        for (int i = 0; i < node->neighbors.size(); i++) {
            copyNode->neighbors.push_back(cloneHelper(node->neighbors[i], visited));

        }
        return copyNode;
    }

    Node* cloneGraph(Node* node) {
        vector<Node *> visited(101, NULL);
        return cloneHelper(node, visited);      
    }
};
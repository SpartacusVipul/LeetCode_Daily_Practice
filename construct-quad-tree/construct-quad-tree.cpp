/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    // similar to other divide and conquer questions,
    // time complexity is O(n^2logn) to base 4
    // we are searching every time within the grids xs xe ys ye
    // in the recursive calls, we are setting xe to xmid not xmid - 1 (similar for other cases)
    // how is it not falling in an infinite loop ?? 
    Node *buildHelper(int xs, int xe, int ys, int ye, vector<vector<int>>& grid) {
        if (xs > xe || xs >= grid.size() || ys > ye || ys >= grid[0].size()) return NULL;
        if (xs == xe && ys == ye) return new Node (grid[xs][ys], true);
        // cout << "s " << xs << " " << xe << " " << ys << " " << ye << endl;
        int oneFlag = 0, zeroFlag = 0;
        for (int i = xs; i < xe; i++) {
            for (int j = ys; j < ye; j++) {
                if (oneFlag == 1 && zeroFlag == 1) break;
                if (grid[i][j] == 1) oneFlag = 1;
                if (grid[i][j] == 0) zeroFlag = 1;
            }
            if (oneFlag == 1 && zeroFlag == 1) break;
        }
        
        if (oneFlag == 0 && zeroFlag == 1) {
            Node *root = new Node(0, false);
            root->isLeaf = true;
            return root;
        } 
        if (zeroFlag == 0 && oneFlag == 1) {
            Node *root = new Node(1, false);
            root->isLeaf = true;
            return root;
        }
        Node *root = new Node(1, false);
        int xmid = xs + (xe - xs) / 2, ymid = ys + (ye - ys) / 2;
        root->topLeft = buildHelper(xs, xmid, ys, ymid, grid);
        root->topRight = buildHelper(xs, xmid, ymid, ye, grid);
        root->bottomLeft = buildHelper(xmid, xe, ys, ymid, grid);
        root->bottomRight = buildHelper(xmid, xe, ymid, ye, grid);
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        return buildHelper(0, grid.size(), 0, grid[0].size(), grid);
    }
};
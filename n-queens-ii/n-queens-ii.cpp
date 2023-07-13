class Solution {
public:
    void backTrack(int &res, int colIndex, int n, set<int> rowPos, set<int> negDiag, set<int> posDiag) {
        if (colIndex == n) {
            res++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (rowPos.find(row) != rowPos.end() ||
                negDiag.find(row - colIndex) != negDiag.end() ||
                posDiag.find(row + colIndex) != posDiag.end()) {
                continue;
            }
            rowPos.insert(row);
            negDiag.insert(row - colIndex);
            posDiag.insert(row + colIndex);
            backTrack(res, colIndex + 1, n, rowPos, negDiag, posDiag);\
            rowPos.erase(row);
            negDiag.erase(row - colIndex);
            posDiag.erase(row + colIndex);
        }
        return ;
    }

    int totalNQueens(int n) {
        set<int> rowPos;
        set<int> negDiag; // r - c 
        set<int> posDiag; // r + c

        int res = 0;
        backTrack(res, 0, n, rowPos, negDiag, posDiag);
        return res;

    }
};
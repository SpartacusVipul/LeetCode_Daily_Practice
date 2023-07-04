class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rowSize = board.size();
        int colSize = board[0].size();
        vector<int> xdir = {-1, 0, 1, 0};
        vector<int> ydir = {0, 1, 0, -1};
        for (int row = 0; row < rowSize; row ++) {
            for (int col = 0; col < colSize; col++) {
                if (board[row][col] == 'O') {
                    queue<pair<int, int>> q;
                    vector<pair<int, int>> gridIndices;
                    int edgeFlag = false;
                    q.push({row, col});
                    while (!q.empty()) {
                        pair<int, int> pos = q.front();
                        q.pop();
                        gridIndices.push_back(pos);
                        if (pos.first == 0 || pos.first == rowSize - 1 || 
                            pos.second == 0 || pos.second == colSize - 1) {
                            edgeFlag = true;
                        }
                        for (int i = 0; i < 4; i++) {
                            int nrow = pos.first + xdir[i];
                            int ncol = pos.second + ydir[i];
                            if (nrow >= 0 && nrow < rowSize && ncol >= 0 && ncol < colSize 
                                && board[nrow][ncol] == 'O') {
                                q.push({nrow, ncol});
                                board[nrow][ncol] = 'X';
                            }
                        }
                    }
                    if (edgeFlag == false) {
                        for (int i = 0; i < gridIndices.size(); i++) {
                            board[gridIndices[i].first][gridIndices[i].second] = 'X';
                        }
                    } else {
                        for (int i = 0; i < gridIndices.size(); i++) {
                            board[gridIndices[i].first][gridIndices[i].second] = 'O';
                        }
                    }
                }

            }
        }

    }
};
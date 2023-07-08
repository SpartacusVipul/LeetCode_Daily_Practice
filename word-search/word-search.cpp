class Solution {
public:
    vector<int> movX = {-1, 0, 1, 0};
    vector<int> movY = {0, 1, 0, -1};
    
    bool backTrack(pair<int, int> pos, vector<vector<int>> &visited, 
                    string cur, vector<vector<char>>& board, string word) {
        if (cur.size() == word.size()) {
            if (cur == word) return true;
            return false;
        }
        for (int i = 0; i < 4; i++) {
            pair<int, int> newPos(pos.first + movX[i], pos.second + movY[i]);
            if (newPos.first < board.size() && newPos.first >= 0 &&
                newPos.second < board[0].size() && newPos.second >= 0 &&
                word[cur.size()] == board[newPos.first][newPos.second] &&
                !visited[newPos.first][newPos.second]) {
                    cur += word[cur.size()];
                    visited[newPos.first][newPos.second] = 1;
                    if (backTrack(newPos, visited, cur, board, word)) return true;
                    cur.pop_back();
                    visited[newPos.first][newPos.second] = 0;
                }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    pair<int, int> pos(i, j);
                    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
                    string cur = "";
                    cur += board[i][j];
                    visited[i][j] = 1;
                    if (backTrack(pos, visited, cur, board, word)) return true;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    void backTrack(int pos, int n, int k, vector<int> &cur, vector<vector<int>> &res) {
        if (k == 0) {
            res.push_back(cur);
            return;
        }

        for (int i = pos; i <= n; i++) {
            cur.push_back(i);
            backTrack(i + 1, n, k - 1, cur, res);
            cur.pop_back();
        }
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        backTrack(1, n, k, cur, res);
        return res;
    }
};
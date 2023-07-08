class Solution {
public:
    // trick is, to have the condition that if curSum < 0, then we 
    // do not try further on that 
    // at every time curSum >= 0
    void backTrack(int n, int curSum, string cur, vector<string> &res) {
        if (cur.size() == 2*n) {
            if (curSum == 0) res.push_back(cur);
        }

        if (cur.size() > 2*n) return;
        if (curSum < 0) return;

        curSum += 1;
        cur += "(";
        backTrack(n, curSum, cur, res);
        curSum -= 1;
        cur.pop_back();

        curSum -= 1;
        cur += ")";
        backTrack(n, curSum, cur, res);
        curSum += 1;
        cur.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        backTrack(n, 0, cur, res);
        return res;
    }
};
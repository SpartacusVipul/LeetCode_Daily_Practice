class Solution {
public:
    // here the input vector pair is used 
    // and whenever a val is added to the cur vector, then it is marked as visited
    // we loop over all elements every time and if any node is node visited
    // we mark it as visited, push to vector, then call backtrack, 
    // then unmark visited, pop from vector, and check for next element
    void backTrack(vector<pair<int, int>> input, vector<int> &cur, vector<vector<int>> &resVec) {
        if (cur.size() == input.size()) {
            resVec.push_back(cur);
        }
        for (int i = 0; i < input.size(); i++) {
            if (input[i].second == 0) {
                cur.push_back(input[i].first);
                input[i].second = 1;
                backTrack(input, cur, resVec);
                input[i].second = 0;
                cur.pop_back();
            }
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<pair<int, int>> input;
        for (int i = 0; i < nums.size(); i++) {
            input.push_back({nums[i], 0});
        }
        vector<int> cur;
        vector<vector<int>> resVec;
        backTrack(input, cur, resVec);
        return resVec;
    }
};
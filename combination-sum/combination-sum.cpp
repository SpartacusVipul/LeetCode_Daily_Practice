class Solution {
public:
    // critical to pass the index variable
    // this is used to avoid repetitions or duplicates 
    // this is used because, everytime we search at index or next of it but not behind index 
    void backTrack(int target, int index, int curSum, vector<int> &candidates, vector<int> &cur, vector<vector<int>> &resVec) {
        if (curSum > target) {
            return;
        }
        if (curSum == target) {
            resVec.push_back(cur);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            curSum += candidates[i];
            cur.push_back(candidates[i]);
            backTrack(target, i, curSum, candidates, cur, resVec);
            curSum -= candidates[i];
            cur.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        vector<vector<int>> resVec;
        backTrack(target, 0, 0, candidates, cur, resVec);
        return resVec;
    }
};
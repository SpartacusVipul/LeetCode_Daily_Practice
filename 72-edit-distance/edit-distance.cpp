class Solution {
public:
    // only mem for now 
    // have a 2d dp, index1 and index2 are used to represent for word1 and word2 
    // for base cases, if index1 exceeds word1.size(), it means there are no more chars in word1
    // so, we need to remove all remaining chars from word2 i.e word2.size() - index2 
    // similarly if index2 >= word2.size(), it means we need to delete remaining chars from word1 
    // if there is a common char, then increase both index1 and index2 , 
    // if there is not common char, check 3 cases 
    // delete word1 char and keep word2 at same 
    // delete word2 char and keep word1 at same 
    // or delete boith word1 and word2 chars and 
    
    int mem(int index1, int index2, string word1, string word2, vector<vector<int>> &dp) {
        if (index1 >= word1.size()) {
            return max(0, (int)word2.size() - index2);
        }
        if (index2 >= word2.size()) {
            return max(0, (int)word1.size() - index1);
        }
        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }

        int res = INT_MAX;
        if (word1[index1] == word2[index2]) {
            res = mem(index1 + 1, index2 + 1, word1, word2, dp);
        } else {
            res = min(mem(index1 + 1, index2, word1, word2, dp), 
                        mem(index1, index2 + 1, word1, word2, dp));
            res = min(res, mem(index1 + 1, index2 + 1, word1, word2, dp));
            res += 1; 
        }
        return dp[index1][index2] = res;
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return mem(0, 0, word1, word2, dp);
    }
};
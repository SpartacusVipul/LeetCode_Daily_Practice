class Solution {
public:
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
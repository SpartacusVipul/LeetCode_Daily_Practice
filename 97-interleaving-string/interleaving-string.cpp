class Solution {
public:

    // maintain 3 incides, for s1, s2 and s3 resp
    // if s1[i] == s3[j] != s2[k] just increment i and j similarly for k and j 
    // if both s1 and s2 have same character, then we have two options 
    // either take s1 or s2, so make both calls and return whichever returns 
    // true 

    bool mem(int i1, int i2, int i3, string s1, string s2, string s3, vector<vector<int>> &dp) {
        if (i1 == s1.size() && i2 == s2.size() && i3 == s3.size()) return true;
        if (dp[i1][i2] != -1) {
            return dp[i1][i2];
        }

        if (i1 < s1.size() && s1[i1] == s3[i3]) {
            if (mem(i1 + 1, i2, i3 + 1, s1, s2, s3, dp)) {
                return true;
            }
        }
        if (i2 < s2.size() && s2[i2] == s3[i3]) {
            if (mem(i1, i2 + 1, i3 + 1, s1, s2, s3, dp)) {
                return true;
            }
        }
        dp[i1][i2] = false;
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return mem(0, 0, 0, s1, s2, s3, dp);
    }
};
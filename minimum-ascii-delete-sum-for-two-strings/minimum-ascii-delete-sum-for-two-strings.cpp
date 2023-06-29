class Solution {
public:
    int mem(int index1, int index2, string s1, string s2, vector<vector<int>> &dp) {
        if (index1 >= s1.size()) {
            int sum = 0;
            while (index2 < s2.size()) {
                sum += s2[index2];
                index2++;
            }
            return sum;
        }
        if (index2 >= s2.size()) {
            int sum = 0;
            while (index1 < s1.size()) {
                sum += s1[index1];
                index1++;
            }
            return sum;
        }
        
        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }

        int res = INT_MAX;
        if (s1[index1] == s2[index2]) {
            res = mem(index1 + 1, index2 + 1, s1, s2, dp);
        } else {
            res = min(s1[index1] + mem(index1 + 1, index2, s1, s2, dp), 
                        s2[index2] + mem(index1, index2 + 1, s1, s2, dp));
            // res = min(res, s1[index1] + s2[index2] + mem(index1 + 1, index2 + 1, s1, s2, dp));
        }
        return dp[index1][index2] = res;
    }

    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        // return mem(0, 0, s1, s2, dp);
        return tab(s1, s2, dp);
    }

    int tab(string s1, string s2, vector<vector<int>> &dp) {
        // base cases 
        int sum = 0;
        for (int i = s2.size() - 1; i >= 0; i--) {
            dp[s1.size()][i] = sum + s2[i];
            sum += s2[i];
        }
        sum = 0;
        for (int i = s1.size() - 1; i >= 0; i--) {
            dp[i][s2.size()] = sum + s1[i];
            sum += s1[i];
        }

        for (int index1 = s1.size() - 1; index1 >= 0; index1--) {
            for (int index2 = s2.size() - 1; index2 >= 0; index2--) {
                int res = INT_MAX;
                if (s1[index1] == s2[index2]) {
                    res = dp[index1 + 1][index2 + 1];
                } else {
                    res = min(s1[index1] + dp[index1 + 1][index2], s2[index2] + dp[index1][index2 + 1]);
                }
                dp[index1][index2] = res;
            }
        }
        return dp[0][0];

    }

};
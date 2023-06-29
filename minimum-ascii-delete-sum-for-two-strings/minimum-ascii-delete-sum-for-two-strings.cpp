class Solution {
public:
    // opt(i, j) represents min ascii sum till index i in s1 and j in s2
    // base cases are 
    // if we reach end of any string, it impliues, we need to delete all other characts of other string
    // so we loop till the end of the other string and add the sum and return the sum
    // other wise, if at any point characters are same, then just increase index1m, index2.
    // otherwise check all options, increasing index1 or index2 and taking min
    // therefore opt(i,j) = opt(i + 1, j + 1) if s1[i] == s2[j]
    // else opt(i,j) = min(s1[i] + opt(i + 1, j), s2[j] + opt(i, j+1))
    // base case is opt(i,j) = sum(j over till s2.size()) if i >= s1.size()
    // opt(i,j) = sum(i over till s1.size()) if j >= s2.size()
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
        //initial value of dp is very important here, for tabulation case
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        // return mem(0, 0, s1, s2, dp);
        return tab(s1, s2, dp);
    }

    int tab(string s1, string s2, vector<vector<int>> &dp) {
        // base cases 
        int sum = 0;
        // here we are filling dp[s1.size()][s2.size() - 1]
        for (int i = s2.size() - 1; i >= 0; i--) {
            dp[s1.size()][i] = sum + s2[i];
            sum += s2[i];
        }
        sum = 0;
        // here we are filling dp[s1.size() - 1][s2.size()]
        for (int i = s1.size() - 1; i >= 0; i--) {
            dp[i][s2.size()] = sum + s1[i];
            sum += s1[i];
        }
        // there might be a case we need dp[s1.size()][s2.size()] 
        // which must be 0, logically, so either set is to zero or initialize the array to 0
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
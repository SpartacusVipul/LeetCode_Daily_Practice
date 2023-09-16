class Solution {
public:
    // similar to other take not take problems 
    // similar to coin change
    int mem(int n, vector<int> &dp) {
        if (n == 0) return 0;
        if (n < 0) return 1e8;
        if (dp[n] != -1) return dp[n];

        int minCount = 1e8;
        for (int i = 1; i <= n; i++) {
            int temp = 1e8;
            if (i * i <= n) {
                temp = 1 + mem(n - (i * i), dp);
            }
            if (temp < minCount) minCount = temp;
        }
        return dp[n] = minCount;

    }

    int numSquares(int n) {
        if (n == 1) return 1;
        vector<int> dp(n + 1, -1);        
        return mem(n, dp);
    }
};
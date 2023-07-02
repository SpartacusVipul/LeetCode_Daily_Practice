class Solution {
public:
    // given n >= 1, also, we are currently at step 0, we 
    // want to go to step n
    vector<int> dp = vector<int>(46, -1);
    int climbStairsMem(int n) {
        if (n <= 1) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = climbStairsMem(n - 1) + climbStairsMem(n - 2);
    }

    int climbStairs(int n) {
        return climbStairsTab(n);
    }

    int climbStairsTab(int n) {
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }    
};
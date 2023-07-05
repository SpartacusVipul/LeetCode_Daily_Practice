class Solution {
public:
    // opt(i) represents the minimum coins to reach this amount
    // we want to find opt(amount) the given amount
    // so, everytime, we loop over couns.size()
    // and try with that coin 
    // if we reach an amount higher than currentAmount, then return INT_MAX
    // if we reach exact amount, return 0
    int mem(long int currentAmount, int amount, vector<int> &coins, vector<int> &dp) {
        if (currentAmount == amount) {
            return 0;
        }
        if (currentAmount > amount) {
            return INT_MAX;
        }
        if (dp[currentAmount] != -1) {
            return dp[currentAmount];
        }
        long int count = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            long int coinCount = mem(currentAmount + coins[i], amount, coins, dp);
            if (coinCount != INT_MAX) {
                count = min(1 + coinCount, count) ;
            } 
        }
        return dp[currentAmount] = count;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int res = mem(0, amount, coins, dp);
        if (res == INT_MAX) return -1;
        return res;
    }
};
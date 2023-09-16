class Solution {
public:
    int mem(vector<int> &coins, vector<int> &dp, int amount) {
        // cout << amount << endl;
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return 1e8;
        }
        if (dp[amount] != -1) return dp[amount];

        int min = 1e8;
        for (int i = 0; i < coins.size(); i++) {
            int temp = 1e8;
            if (coins[i] <= amount) { // this was missed in my first attempt 
                temp = 1 + mem(coins, dp, amount - coins[i]);
                // cout << "temp " << temp << endl;
            }
            if (temp < min) {
                min = temp;
            }
        }
        cout << min << endl;
        return dp[amount] = min;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int res = mem(coins, dp, amount);
        return res != 1e8 ? res : -1;    
    }
};
class Solution {
public:
    // representative for 0 1 knapsack, I think bounded
    // similar to take not take logic, but implemented differently

    int mem(int index, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if (target == 0) {
            return 1;
        }
        if (index >= nums.size()) {
            return 0;
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }
        // here also, we are checking with taking and not taking all the next indices
        for (int i = index; i < nums.size(); i++) {
            if (target >= nums[i]) {
                if (mem(i + 1, target - nums[i], nums, dp) == 1) {
                    return dp[index][target] = 1;
                }
            }
        }
        return dp[index][target] = 0;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int target = sum / 2;
        if (sum % 2 != 0) {
            return false;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        int val =  mem(0, target, nums, dp);
        return val;
        // return tab(target, nums, dp);
    }

    int tab(int target, vector<int> &nums, vector<vector<int>> &dp) {
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = 1;
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = 0; j <= target; j++) {                
                for (int k = i; k < nums.size(); k++) {
                    if (target >= nums[k]) {
                        if (dp[k][j] == 1) {
                            dp[i][j] = 1;
                            break;
                        }
                    }
                }

            }
        }
        return dp[0][target];
    }
};
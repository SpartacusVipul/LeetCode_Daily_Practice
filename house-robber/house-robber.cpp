class Solution {
public:
    // opt(i) be maximum loot till house i, may or maynot include house i
    // opt(i) = max(cost[i] + opt(i - 2), opt(i - 1))
    // either we can loot i - 2house and i house, 
    // or we have looted i - 1house and do nothing now
    
    int mem(int index, vector<int> &nums, vector<int> &dp) {
        if (index < 0) {
            return 0;
        }
        if (index == 0) {
            return nums[index];
        }
        if (index == 1) { // doubt
            return max(nums[0], nums[index]);
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        // but this is just overwriting step, not needed at all, 
        // when mem function returns it sets the value in dp table, no need to assign again
        dp[index - 2] = mem(index - 2, nums, dp); 
        dp[index - 1] = mem(index - 1, nums, dp);
        return dp[index] = max(dp[index - 2] + nums[index], dp[index - 1]);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return mem(nums.size() - 1, nums, dp);
        // return tab(nums, dp);
    }

    int tab(vector<int> nums, vector<int> &dp) {
        if (nums.size() == 1) {
            return nums[0];
        } 
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }  


};
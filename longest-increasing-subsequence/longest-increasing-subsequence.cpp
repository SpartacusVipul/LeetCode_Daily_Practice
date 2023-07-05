class Solution {
public:
    
    int mem(int index1, int index2, vector<int> &nums, vector<vector<int>> &dp) {
        if (index1 == nums.size()) {
            return 0;
        }
        if (dp[index1][index2 + 1] != -1) {
            return dp[index1][index2 + 1];
        }
        int len1 = 0, len2 = 0;
        if (index2 == -1 || nums[index1] > nums[index2]) {
            len1 = 1 + mem(index1 + 1, index1, nums, dp);
        } 
        len2 = mem(index1 + 1, index2, nums, dp);
        
        return dp[index1][index2 + 1] = max(len1, len2);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1)); 
        return mem(0, -1, nums, dp);

    }
    // go through again for tabulation code
};
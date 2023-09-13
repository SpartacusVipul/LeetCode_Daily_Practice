class Solution {
public:
    // either leave out the last element 
    // or leave out the first element 
    // ans = max(leaving first , leaving last)
    int mem(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        
        vector<int> dp(nums.size(), 0);
        dp[0] =nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> firstRemoved, lastRemoved;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0) {
                firstRemoved.push_back(nums[i]);
            }
            if (i != nums.size() - 1) {
                lastRemoved.push_back(nums[i]);
            }
        }
        return max(mem(firstRemoved), mem(lastRemoved));
    }
};
class Solution {
public:
    // basic idea is to try to find the start index for a 
    // consecute sequence
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> allSet;
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            allSet.insert(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            // wow, this is a nice optimization
            // here for set 6, 5,4, 3, 2, 1
            // if we try to find nums[i] - 1
            // only the start of the sequence will have this as true
            // all others will have some value
            // so using this we redcued significant time
            if (allSet.find(nums[i] - 1) == allSet.end()) {
                int start = nums[i];
                int count = 0;
                while (allSet.find(start) != allSet.end()) {
                    start++;
                    count++;
                }
                maxLen = max(maxLen, count);
            }
            
        }
        return maxLen;
    }
};
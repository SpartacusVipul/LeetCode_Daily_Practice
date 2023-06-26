class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int left = 0, right = 0;
        vector<string> res;
        
        while (left < nums.size()) {
            int right = left;
            while (right < nums.size() - 1 && nums[right] + 1 == nums[right + 1]) {
                right++;
            }
            cout << left << " " << right << endl;
            string interval = "";
            if (nums[left] == nums[right]) {
                interval = to_string(nums[left]);
            } else {
                interval = to_string(nums[left]) + "->" + to_string(nums[right]);
            }
            cout << interval << endl;
            res.push_back(interval);
            left = right + 1;
        }
        return res;
    }
};
class Solution {
public:
    // basic idea is we merge the consecutive numbers into windows
    // if the window size is 1 then just the element
    // if greater than 1, then in left->right format
    // left is start index, right is end index
    // if left and right are same then 1 len window
    // if not, then other case
    // update left to next of right
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
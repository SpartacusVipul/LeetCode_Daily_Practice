class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int left = 0, right = nums.size() -1;
        while (left <= right) {
            // cout << left << " " << right << endl;
            int mid = left + (right - left) / 2;
            if ((mid - 1 < 0 || nums[mid - 1] != nums[mid]) && (mid + 1 == nums.size() || nums[mid] != nums[mid + 1])) {
                return nums[mid];
            } 
            int leftSize = 0;
            if (mid - 1 >= 0 && nums[mid - 1] == nums[mid]) {
                leftSize = mid - 1;
            } else {
                leftSize = mid;
            }
            if (leftSize % 2 == 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }

        }
        return -1;
    }
};
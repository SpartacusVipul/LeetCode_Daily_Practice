class Solution {
public:
    // nice problem the target can be greater than all the elements in the array
    // in which case it must be inserted in the end beyond nums.size() - 1; so the 
    // search space in this problem is right = nums.size()
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    } 
};
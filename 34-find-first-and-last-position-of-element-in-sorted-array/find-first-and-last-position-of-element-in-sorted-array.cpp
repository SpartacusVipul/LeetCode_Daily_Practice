class Solution {
public:
    // this issue with < or <= is solved in opt function below
    // really need to check when to use <= and < conditions in the while loop  
    // basic idea is calling the binary search function twice
    // first time to find the starting position, another time to find the ending position
    // so when target is equal to mid, if we want to find the starting position, 
    // udpate the index to mid, and continue the search in the left half (right = mid - 1)
    // simil;arly for finding the end index 
    int binarySearchBiased(vector<int>& nums, int target, int biasFlag) {
        
        int left = 0, right = nums.size() -1;
        int index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                if (biasFlag == 1) {
                    right = mid - 1;
                    index = mid;
                } else if (biasFlag == 0) {
                    left = mid + 1;
                    index = mid;
                }
            }
        }
        return index;
    }

    vector<int> searchRangeOld(vector<int>& nums, int target) {
        int start = binarySearchBiased(nums, target, 1);
        int end =  binarySearchBiased(nums, target, 0);
        return {start, end};
    }

    int binarySearchBiasedOpt(vector<int> &nums, int target, int bias) {
        int left = 0, right = nums.size();
        int index = -1;
        while (left < right) {
            int mid = left +  (right - left) / 2;
            // cout << left << " " << right << " " << mid << endl;
            if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (bias == 1) {
                left = mid + 1;
                index = mid;
            } else {
                right = mid;
                index = mid;
            }
        }
        return index;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = binarySearchBiasedOpt(nums, target, 0);
        int end =  binarySearchBiasedOpt(nums, target, 1);
        return {start, end};
    }
};
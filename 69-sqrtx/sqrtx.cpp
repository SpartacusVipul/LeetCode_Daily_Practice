class Solution {
public:
    // basic idea is we keep decreasing the search space
    // mid = (left + right) / 2
    // if mid * mid > x implies, we need to search in left 
    // half, otherwise need to search in right half
    int mySqrt(int x) {
        int left = 0, right = x;
        int res = 0;
        while (left <= right) {
            long int mid = left + (right - left) / 2;
            if (mid * mid > x) {
                right = mid - 1;
            } else if (mid * mid < x) {
                left = mid + 1;
                res = mid;
            } else {
                return mid;
            }
        }
        return res;
    }
};
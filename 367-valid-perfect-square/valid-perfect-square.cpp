class Solution {
public:
    bool isPerfectSquare(int num) {
        long int left = 1, right = num;
        while (left < right) {
            long int mid = left + (right - left) / 2;
            if (mid * mid > num) {
                right = mid - 1;
            } else if (mid * mid < num) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        if (left == right) {
            return left * left == num;
        }
        return false;
    }
};
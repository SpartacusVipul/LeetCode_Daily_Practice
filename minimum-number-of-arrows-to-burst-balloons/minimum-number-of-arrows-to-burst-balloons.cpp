class Solution {
public:
    // wow, need to keep below a and b as references, not copies
    // it is causing TLE errors in some cases
    static bool cmp (vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
    // sort based on end times
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        // idea is we have already fired an arrow to shootdown the first balloon, the balloon with earliest ending time
        // so we start arrow with 1
        int arrow = 1; // we are setting it to 1, because, for the first window, we are going to fire an arrow 
        int end = points[0][1];
        // basic idea is, the window with earliest end time, how many balloons can it cover
        int n = points.size();
        int newStart = points[0][0];
        for (int i = 1; i < n; i++) {
            newStart = points[i][0];
            if (end < newStart) { // whenever we encounter a window whose start exceeeds previous end, we shoot a new arrow 
                arrow++; // ajnd again check which all windows are covered in it
                end = points[i][1]; 
            }
        }
        return arrow;
    }
};
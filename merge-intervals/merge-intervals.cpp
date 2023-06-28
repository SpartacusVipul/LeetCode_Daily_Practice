class Solution {
public:

    // basic idea is sort based on start time of the interval
    // now if a new window which has higher start time than the current winodw, if less than 
    // the end of the current window, then we include this window in our current window
    // the end of the current window is updated as max(current end, new end)
    // if at any point new start is greater than current end, no overlap
    // then we simply write the currentwidnwo t res vector and create new current windpw
    static bool compareInterval(vector<int> b1, vector<int> b2)
    {
        return (b1[0] < b2[0]);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if (intervals.size() == 0) {
            return mergedIntervals;
        }

        sort(intervals.begin(), intervals.end(), compareInterval);
        int winStart = intervals[0][0], winEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int newWinStart = intervals[i][0];
            int newWinEnd = intervals[i][1];
            if (winEnd >= newWinStart) {
                winEnd = max(winEnd, newWinEnd);
            } else {
                mergedIntervals.push_back({winStart, winEnd});
                winStart = newWinStart;
                winEnd = newWinEnd;
            }
        }
        mergedIntervals.push_back({winStart, winEnd});
        return mergedIntervals;
    }
};
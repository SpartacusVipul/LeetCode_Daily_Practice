class Solution {
public:
    static bool compare(vector<int> b1, vector<int> b2) {
        return b1[0] < b2[0];
    }
    // similar to merge intervals
    // just insert the new interval and sort the whole thing
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> currentInterval = intervals[0];
        vector<vector<int>> mergedInterval;
        for (int i = 1; i < intervals.size(); i++) {
            if (currentInterval[1] >= intervals[i][0]) {
                currentInterval[1] = max(intervals[i][1], currentInterval[1]);
            } else {
                mergedInterval.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }
        mergedInterval.push_back(currentInterval);
        return mergedInterval;
    }

    

    vector<vector<int>> insert2(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> mergedInterval;
        if (intervals.size() == 0) {
            mergedInterval.push_back(newInterval);
            return mergedInterval;
        }

        sort(intervals.begin(), intervals.end(), compare);

        int index = 0;
        // no overlap case
        while (index < intervals.size() && intervals[index][1] < newInterval[0]) { 
            mergedInterval.push_back(intervals[index]);
            index++;
        }
        //first overlap detected 
        vector<int> singleMergedInterval = newInterval;
        while (index < intervals.size() && intervals[index][0] <= newInterval[1]) {
            singleMergedInterval[0] = min(singleMergedInterval[0], intervals[index][0]);
            singleMergedInterval[1] = max(singleMergedInterval[1], intervals[index][1]);
            index++;
        }
        mergedInterval.push_back(singleMergedInterval);

        //pushing rest of the intervals
        while (index < intervals.size()) {
            mergedInterval.push_back(intervals[index]);
            index++;
        }

        return mergedInterval;
    }
    
    void insertAtPlace(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int index = 0;
        while (index < intervals.size() && intervals[index][0] < newInterval[0] ) {
            index++;
        }
        intervals.insert(intervals.begin() + index, newInterval);
    }

    vector<vector<int>> insert_v1(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> mergedInterval;
        if (intervals.size() == 0) {
            mergedInterval.push_back(newInterval);
            return mergedInterval;
        }

        sort(intervals.begin(), intervals.end(), compare);
        insertAtPlace(intervals, newInterval);
        int index = 0;
        vector<int> tempInterval = intervals[0];
        while (index < intervals.size()) {
            if (tempInterval[1] >= intervals[index][0]) {
                tempInterval[1] = max(intervals[index][1], tempInterval[1]);
                index++;
            } else {
                mergedInterval.push_back(tempInterval);
                tempInterval = intervals[index];
                index++;
            }
        }
        mergedInterval.push_back(tempInterval);
        return mergedInterval;
    }
};
class Solution {
public:
    // there might be a better solution with time complexity O(m + n)
    // will look into it later
    // this takes mlogn

    int searchIndex(vector<int>& row) {
        int left = 0, right = row.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (row[mid] < 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return row[left] < 0 ? left : row.size();
    }

    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            int index = searchIndex(grid[i]);
            count += grid[i].size() - index;
        }
        return count;
    }
};
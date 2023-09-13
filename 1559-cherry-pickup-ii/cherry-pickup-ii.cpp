class Solution {
public:
    // opt [i, j1, j2] = if j1 == j2 cost[i, j1] + 9 possibilities

    int mem(int rowIndex, int colIndex1, int colIndex2, int colSize, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        if (colIndex1 < 0 || colIndex1 >= colSize || colIndex2 < 0 || colIndex2 >= colSize) return INT_MIN;

        if (rowIndex == grid.size() - 1) {
            if (colIndex1 == colIndex2) return grid[rowIndex][colIndex1];
            else return grid[rowIndex][colIndex1] + grid[rowIndex][colIndex2];
        }

        if (dp[rowIndex][colIndex1][colIndex2] != -1) return dp[rowIndex][colIndex1][colIndex2];

        int maxi = INT_MIN;
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2 ++) {
                int value = 0;
                if (colIndex1 == colIndex2) {
                    value = grid[rowIndex][colIndex1];
                } else {
                    value = grid[rowIndex][colIndex1] + grid[rowIndex][colIndex2];
                }
                value += mem(rowIndex + 1, colIndex1 + d1, colIndex2 + d2, colSize, grid, dp);
                maxi = max(maxi, value);
            }
        }

        return dp[rowIndex][colIndex1][colIndex2] = maxi;
     }

    int cherryPickup(vector<vector<int>>& grid) {
        int colSize = grid[0].size();
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return mem(0, 0, grid[0].size() - 1, colSize, grid, dp);
    }
};
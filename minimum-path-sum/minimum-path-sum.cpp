class Solution {
public:
    // important to keep &grid, otherwise it is copied everytime and causes TLE MLE
    int mem(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if (x < 0 || y < 0) {
            return INT_MAX;
        }
        if (x == 0 && y == 0) {
            return grid[0][0];
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        return dp[x][y] = min(mem(x - 1, y, grid, dp), mem(x, y - 1, grid, dp)) + grid[x][y];
    }
    // opt(i,j) represents the minimum path sum to reach index i, j in the grid
    // opt(i, j) = min(opt(i - 1, j), opt(i, j-1)) + grid[i][j] 
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        // return mem(grid.size() - 1, grid[0].size() - 1, grid, dp);
        return tab(grid, dp);
    }

    int tab(vector<vector<int>> &grid, vector<vector<int>> &dp) {
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        
        for (int i = 1; i < grid[0].size(); i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[grid.size() - 1][grid[0].size() - 1];
    }

};
class Solution {
public:

    int mem(int x, int y, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp) {
        if (x < 0 || y < 0) {
            return 0;
        }
        if (x == 0 && y == 0) {
            return obstacleGrid[0][0] == 0 ? 1 : 0;
        }
        
        int top = 0, left = 0;
        if (x - 1 >= 0 && obstacleGrid[x - 1][y] != 1) {
            top = mem(x - 1, y, obstacleGrid, dp);
        }
        if (y - 1 >= 0 && obstacleGrid[x][y - 1] != 1) {
            left = mem(x, y - 1, obstacleGrid, dp);
        }
        if (obstacleGrid[x][y] == 1) {
            return dp[x][y] = 0;
        }
        return dp[x][y] = top + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return mem(m - 1, n - 1, obstacleGrid, dp);
        return tab(m, n, obstacleGrid, dp);
    }

    int tab(int m, int n, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp) {
        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int i = 1; i < m; i++) {
            dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];
        }
        for (int i = 1; i < n; i++) {
            dp[0][i] = obstacleGrid[0][i] == 1 ? 0 : dp[0][i - 1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int top = 0, left = 0;
                if (i - 1 >= 0 && obstacleGrid[i - 1][j] != 1) {
                    top = dp[i - 1][j];
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] != 1) {
                    left = dp[i][j - 1];
                }
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = top + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
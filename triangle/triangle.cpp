class Solution {
public:
    int mem(int rowIndex, int colIndex, vector<vector<int>>& triangle ,vector<vector<int>>& dp) {
        if (colIndex < 0 || rowIndex < 0) {
            return INT_MAX;
        }

        if (colIndex == 0 && rowIndex == 0) {
            return triangle[0][0];
        }
        if (dp[rowIndex][colIndex] != -1) {
            return dp[rowIndex][colIndex];
        }
        int leftParent = INT_MAX, sameParent = INT_MAX;
        if (colIndex - 1 >= 0 && rowIndex - 1>= 0) {
            leftParent = mem(rowIndex - 1, colIndex - 1, triangle, dp);
        }
        if (rowIndex - 1 >= 0 && colIndex < triangle[rowIndex - 1].size()) {
            sameParent = mem(rowIndex - 1, colIndex, triangle, dp);
        }
        // if (leftParent == INT_MAX && sameParent == INT_MAX) {
        //     return dp[rowIndex][colIndex] = INT_MAX; 
        // }
        return dp[rowIndex][colIndex] = min(leftParent, sameParent) + triangle[rowIndex][colIndex];
    }
    // opt(i,j) represents minimum path sum till index i, j
    // opt(i, j) = min(opt(i-1, j -1), opt(i - 1, j))
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));

        // int ans = INT_MAX;
        // for (int i = 0; i < triangle.size(); i++) {
        //     ans = min(ans, mem(triangle.size() - 1, i, triangle, dp));
        // }     
        // return ans;

        return tab(triangle, dp);
    }

    int tab(vector<vector<int>>& triangle ,vector<vector<int>>& dp) {
        dp[0][0] = triangle[0][0];
        if (triangle.size() == 1) {
            return dp[0][0];
        }
        int ans = INT_MAX;
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int leftParent = INT_MAX, sameParent = INT_MAX;
                if (j - 1 >= 0 && i - 1>= 0) {
                    leftParent = dp[i - 1][j - 1];
                }
                if (i - 1 >= 0 && j < triangle[i - 1].size()) {
                    sameParent = dp[i - 1][j];
                }
                dp[i][j] = min(leftParent, sameParent) + triangle[i][j];
                if (i == triangle.size() - 1) {
                    ans = min(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
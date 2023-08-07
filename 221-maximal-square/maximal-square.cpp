class Solution {
public:
    int min3 (int a, int b, int c) {
        int r1 = min(a,b);
        int r2 = min(r1, c);
        return r2;
    }
    int finalAnswer = INT_MIN;
    int mem(int x, int y, vector<vector<char>>& matrix, vector<vector<int>>& dp) {
        if (x < 0 || y < 0) {
            return 0;
        }

        int left = 0, upleft = 0, up = 0;
        if (y - 1 >= 0) {
            left = mem(x, y - 1, matrix, dp);
        }
        if (x - 1 >= 0 && y - 1 >= 0) {
            upleft = mem(x - 1, y - 1, matrix, dp);
        }
        if (x - 1 >= 0) {
            up = mem(x - 1, y, matrix, dp);
        }

        if (matrix[x][y] == '0') {
            dp[x][y] = 0;
            finalAnswer = max(finalAnswer, dp[x][y]);
            return dp[x][y];
        } else {
            dp[x][y] = min3(left, upleft, up) + 1;
            finalAnswer = max(finalAnswer, dp[x][y]);
            return dp[x][y];
        }
    }

    // opt(i, j) represent the maximum square that can be formed at that index
    // opt(i, j) = 0 if matrix[i][j] = 0
    // else opt(i, j) = min(opt(i, j - 1), opt(i - 1, j - 1), opt(i - 1, j)) + 1 
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // mem(m - 1, n - 1, matrix, dp);
        // return finalAnswer * finalAnswer;

        int ans = tab(matrix, dp);
        return ans * ans;
    }

    // for initial filling of dp, below things need o be considered
    // as ther is no base case in tabulation
    // dp[i][j] = 0 if matrix[i][j] = 0
    // dp[i][j] = min(dp[i][j - 1], dp[i - 1][j -1], dp[i - 1][j]) + 1
    // here, since when we go beyond matrix, we return 0, min will be 0, so dp[i][j] = 0 if matrix[i][j] == 0 and dp[i][j] = 1if matrix[i][j] == 1
    // at all the top most rows and left most colums, we set dp[i][j] = matrix[i][j]
    int tab(vector<vector<char>>& matrix, vector<vector<int>>& dp) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 1 && n == 1) {
            return matrix[0][0] == '0' ? 0 : 1;
        }
        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] - '0'; // earlier made a mistake in this line, note that matrix is a char array
            ans = max(ans, dp[i][0]); // if a 2 * 2 array, in the nested for loop below we only update 1 1 element, if there is no 1 in that then we get wrong anwer
        } // so update ans here, 
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i] - '0';
            ans = max(ans, dp[0][i]);
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int left = 0, upleft = 0, up = 0;
                if (j - 1 >= 0) {
                    left = dp[i][j - 1];
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    upleft = dp[i - 1][j - 1];
                }
                if (i - 1 >= 0) {
                    up = dp[i - 1][j];
                }

                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = min3(left, upleft, up) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
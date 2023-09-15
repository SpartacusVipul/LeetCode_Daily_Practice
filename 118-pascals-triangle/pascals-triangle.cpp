class Solution {
public:
    // some sort of dp 
    // that uses what ever is calculated in the prvious row to calculte for current row
    // the trick is to use a deque and add a 0 at front and back, so that 
    // every time for caluclating new row dp[i][j] = prevrow[j] + prevrow[j + 1]
    // here prevrow is updated deque with 0 at front and back
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> resVec;
        resVec.push_back({1});
        
        for (int i = 1; i < numRows; i++) {
            deque<int> rowDeq(resVec[i - 1].begin(), resVec[i - 1].end());
            rowDeq.push_front(0);
            rowDeq.push_back(0);
            vector<int> rowVec;

            for (int c = 0; c < i + 1; c++) {
                rowVec.push_back(rowDeq[c] + rowDeq[c + 1]);
            }    
            resVec.push_back(rowVec);
        }
        return resVec;
    }
};
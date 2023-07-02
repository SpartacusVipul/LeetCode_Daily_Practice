class Solution {
public:
    //O(mn^2)
    // for loop for wordDict, 
    // for every word check if it is present, 
    // if present, then check for new index
    // base case evernutally will go till s.size()
    // opt(i) represents if the substring from 0 to i is found in the wordDict or not 
    bool mem(int index, string s, vector<string>& wordDict, vector<int> &dp) {
        if (index >= s.size()) {
            return true;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        for (int i = 0; i < wordDict.size(); i++) {
            string tempString = s.substr(index, wordDict[i].size());
            if (tempString == wordDict[i]) {
                bool flag = mem(index + wordDict[i].size(), s, wordDict, dp);
                if (flag) {
                    return dp[index] = true;
                }
            }
        }
        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, 0);
        // return mem(0, s, wordDict, dp);
        return tab(s, wordDict, dp);
    }
    

    bool tab(string s, vector<string>& wordDict, vector<int> &dp) {
        dp[s.size()] = true;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = 0; j < wordDict.size(); j++) {
                if (i + wordDict[j].size() > s.size()) {
                    continue;
                } else {
                    string tempString = s.substr(i, wordDict[j].size());
                    if (tempString == wordDict[j]) {
                        // here at first i + wordDict[j].size() = s.size()
                        // so the base case of setting dp[s.size()] = true is important
                        if (dp[i] == 0) {
                            dp[i] = dp[i + wordDict[j].size()]; // how is this ok    
                        }
                    }
                }
            }
        } 
        // cout << dp[0] << endl;
        return dp[0];
    }

};
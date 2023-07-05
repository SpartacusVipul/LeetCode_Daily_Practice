class Solution {
public:
    // babad
    //  1,  0, -1, -1, -1
    // -1,  1,  0, -1, -1
    // -1, -1,  1,  0, -1
    // -1, -1, -1,  1,  0
    // -1, -1, -1, -1,  1
    // opt(i, j) is a bool to let us know if the string from i to j is a palindrome
    // baic idea is for substring (i, j), if s[i] == s[j] and substr(i + 1, j - 1) is palindrome, then i,j is palindrome
    // base case, every character is a 1 length palindrome
    // there is something about two or even length palindromes, but didnt understood completely
    // but even two length palindromes are filled as part of base case, where s[i] == s[i + 1] then two length palindrome
    // for length greater than 2, if s[i] == s[j] && i + 1, j - 1 is a palindrome (meining dp[i + 1][ j - 1]) then dp[i][j] is palindrome
    // always keep updating si, se which represnt the start and end index of the longest substring
    // remember the pattern used in the for loop to iterate over diagonally, will be useful later on
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        int maxLen = 0;
        int si, se;
        for (int i = 0; i < s.size(); i++) { // all single char palindromes
            dp[i][i] = 1;
            si = i;
            se = i;
        }
        
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 2;
                maxLen = 2;
                si = i;
                se = i + 1;
            }
        }

        // one pattern to remember for iterating over diagonal
        for (int diff = 2; diff < s.size(); diff++) { 
            for (int i = 0; i < s.size() - diff; i++) {
                int j = i + diff;
                if (s[i] == s[j] && dp[i + 1][j - 1] != -1) {
                    dp[i][j] = dp[i + 1][ j - 1] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                    si = i;
                    se = j;
                }
            }
        }
        string res = s.substr(si, se - si + 1);
        return res;

    }
};
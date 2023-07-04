class Solution {
public:
    // a little similar to dfs
    // bassically trying all possibilities
    vector<string> resStrings;
    void generateStrings(int index, string digits, vector<vector<char>> digitMap, string runningString) {
        if (index == digits.size()) {
            resStrings.push_back(runningString);
            return;
        }
        int mappedDigit = digits[index] - '0';
        for (int i = 0; i < digitMap[mappedDigit].size(); i++) {
            runningString += digitMap[mappedDigit][i];
            generateStrings(index + 1, digits, digitMap, runningString);
            runningString.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return resStrings;
        }
        vector<vector<char>> digitMap(10, vector<char>());
        digitMap[2] = {'a', 'b', 'c'};
        digitMap[3] = {'d', 'e', 'f'};
        digitMap[4] = {'g', 'h', 'i'};
        digitMap[5] = {'j', 'k', 'l'};
        digitMap[6] = {'m', 'n', 'o'};
        digitMap[7] = {'p', 'q', 'r', 's'};
        digitMap[8] = {'t', 'u', 'v'};
        digitMap[9] = {'w', 'x', 'y', 'z'};

        string runningString = "";
        generateStrings(0, digits, digitMap, runningString);
        return resStrings;
    }
};
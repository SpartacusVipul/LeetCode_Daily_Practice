class Solution {
public:
    // trick is to use the max function as it is used here on strings
    // it works here because of order 
    // it checks char by character 
    string removeDigit(string number, char digit) {
        string res = "";
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == digit) {
                res = max(res, number.substr(0, i) + number.substr(i + 1));
            }
        }
        return res;
    }
};
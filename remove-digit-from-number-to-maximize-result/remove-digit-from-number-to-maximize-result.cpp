class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<string> nums;
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == digit) {
                nums.push_back(number.substr(0, i) + number.substr(i + 1));
            }
        }
        sort(nums.begin(), nums.end());
        return nums.back();
    }
};
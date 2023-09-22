class Solution {
public:
    // if even in the end nothing is found that is higher than target
    // just return the first character 
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        while (left < right) {
            cout << left << " " << right << endl;
            int mid = left + (right - left) / 2;
            if (letters[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return letters[left] > target ? letters[left] : letters[0];
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        int aPos = a.size() - 1;
        int bPos = b.size() - 1;
        int carry = 0;
        string res = "";
        while (aPos >= 0 || bPos >= 0 || carry > 0) {
            int sum = 0;
            if (aPos >= 0) {
                sum += a[aPos] - '0';
                aPos--;
            }
            if (bPos >= 0) {
                sum += b[bPos] - '0';
                bPos--;
            }
            sum += carry;
            carry = sum / 2;
            res += ('0' + (sum % 2));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
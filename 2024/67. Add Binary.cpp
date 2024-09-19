class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int carry = 0, i = (int)a.length() - 1, j = (int)b.length() - 1;
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            ret += '0' + (sum % 2);
            carry = sum / 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
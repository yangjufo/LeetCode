class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int tmp = carry;
            if (i >= 0) {
                tmp += a[i] - '0';
                i--;
            } 
            if (j >= 0) {
                tmp += b[j] - '0';
                j--;
            }
            ans += (tmp % 2) + '0';
            carry = tmp / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
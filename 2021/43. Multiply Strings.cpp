class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        vector<int> product(m + n, 0);
        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0; j--) {                
                product[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }        
        string res;
        int carry = 0;
        for (int i = m + n - 1; i >= 0; i--) {
            int sum = product[i] + carry;            
            res += (sum % 10) + '0';
            carry = sum / 10;
        }                
        reverse(res.begin(), res.end());
        int start = 0;
        while (start < res.length() && res[start] == '0') {
            start++;
        }
        return (res.length() > start) ? res.substr(start) : "0";
    }
};
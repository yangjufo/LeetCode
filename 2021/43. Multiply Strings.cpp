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

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> p(num1.length() + num2.length(), 0);        
        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0');                
                p[i + j + 1] += product;
            }
        }
        string res;
        int carry = 0;
        for (int i = p.size() - 1; i >= 0; i--) {
            int sum = p[i] + carry;            
            res += to_string(sum % 10);            
            carry = sum / 10;            
        }        
        if (carry > 0 || res.empty()) {
            res += to_string(carry);
        }
        reverse(res.begin(), res.end());
        int i = 0;
        while (i + 1 < res.length() && res[i] == '0') {
            i++;
        }
        return res.substr(i);
    }
};
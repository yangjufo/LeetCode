class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> digits;
        for (char c : num) {            
            while (!digits.empty() && k > 0 && c < digits.top()) {
                digits.pop();
                k--;
            }
            digits.push(c);
        }
        while (!digits.empty() && k > 0) {
            digits.pop();
            k--;
        }        
        string res;
        while (!digits.empty()) {
            res += digits.top();
            digits.pop();
        }
        
        reverse(res.begin(), res.end());
        int start = 0;
        while (start < res.size() && res[start] == '0') {
            start++;
        }
        res = res.substr(start);
        return res.empty() ? "0" : res;
    }
};
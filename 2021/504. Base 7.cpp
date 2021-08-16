class Solution {
public:
    string convertToBase7(int num) {
        string res, sign = (num < 0) ? "-" : "";
        num = abs(num);
        while (num >= 7) {
            res += to_string(num % 7);
            num /= 7;
        }       
        res += to_string(num);        
        reverse(res.begin(), res.end());
        return sign + res;
    }
};
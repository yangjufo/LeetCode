class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string newS;
            int sum = 0;
            for (int i = 0; i < s.length(); i++) {
                if (i > 0 && i % k == 0) {
                    newS += to_string(sum);
                    sum = 0;
                }
                sum += s[i] - '0';
            }
            s = newS + to_string(sum);
        }
        return s;
    }
};
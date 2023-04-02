class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int count_0 = 0, count_1 = 0, res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                if (i != 0 && s[i - 1] == '1') {
                    count_0 = 1;
                    count_1 = 0;
                } else if (i != 0 && s[i - 1] == '0') {
                    count_0++;
                } else {
                    count_0 = 1;
                }
            } else {
                count_1++;
                res = max(res, min(count_0 * 2, count_1 * 2));
            }
        }
        return res;
    }
};
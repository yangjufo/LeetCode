class Solution {
public:
    int maxPower(string s) {
        int start = 0, res = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[start]) {
                start = i;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};
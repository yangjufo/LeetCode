class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int remain = mean * (n + rolls.size());
        for (int r : rolls) {
            remain -= r;
        }
        int val = remain / n, extra = remain % n;
        if (val < 1 || val > 6 || (val == 6 && extra > 0)) {
            return {};
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (i < extra) {
                res.push_back(val + 1);
            } else {
                res.push_back(val);
            }            
        }
        return res;
    }
};
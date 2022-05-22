class Solution {
public:
    int minimumLines(vector<vector<int>>& s) {
        if (s.size() == 1) return 0;
        if (s.size() <= 2) return 1;
        sort(s.begin(), s.end(), [](vector<int>& l, vector<int>& r) {
           return l[0] < r[0];
        });
        int count = 1;
        for (int i = 2; i < s.size(); i++) {
            if ((long long)(s[i][1] - s[i - 1][1]) * (s[i - 1][0] - s[i - 2][0]) != (long long)(s[i][0] - s[i - 1][0]) * (s[i - 1][1] - s[i - 2][1])) {
                count++;
            }
        }
        return count;
    }
};
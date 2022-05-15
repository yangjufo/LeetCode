class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        special.push_back(top + 1);
        int prev = bottom - 1, res = 0;
        for (int p : special) {
            res = max(p - prev - 1, res);
            prev = p;
        }
        return res;
    }
};
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, tmp = 0;
        for (int n : gain) {
            tmp += n;
            res = max(tmp, res);
        }
        return res;
    }
};
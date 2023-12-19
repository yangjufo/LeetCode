class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1) {
            return {0, 1};
        }
        vector<int> prev = grayCode(n - 1);
        vector<int> res;
        for (int v : prev) {
            res.push_back((v << 1) + 0);
        }
        for (int i = prev.size() - 1; i >= 0; i--) {
            res.push_back((prev[i] << 1) + 1);
        }
        return res;
    }
};
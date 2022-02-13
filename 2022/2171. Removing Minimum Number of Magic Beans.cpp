class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        vector<long long> preSum(beans.size() + 1);
        for (int i = 0; i < beans.size(); i++) {
            preSum[i + 1] = preSum[i] + beans[i];
        }
        long long res = preSum.back();
        for (int i = 0; i < beans.size(); i++) {
            if (i > 0 && beans[i] == beans[i - 1]) {
                continue;
            }
            long long tmp = preSum[i] + preSum.back() - preSum[i + 1] - beans[i] * (beans.size() - i - 1);
            res = min(res, tmp);
        }
        return res;
    }
};
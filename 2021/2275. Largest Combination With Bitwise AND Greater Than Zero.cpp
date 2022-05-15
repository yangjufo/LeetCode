class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i, count = 0;
            for (int c : candidates) {
                if ((c & mask) != 0) {
                    count++;
                }
            }
            res = max(res, count);
        }
        return res;
    }
};
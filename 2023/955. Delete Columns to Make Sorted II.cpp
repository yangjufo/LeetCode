class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<bool> sorted(strs.size(), false);
        int count = 0;
        for (int j = 0; j < strs[0].size(); j++) {
            int i = 0;
            for (i = 0; i < (int)strs.size() - 1; i++) {
                if (!sorted[i] && strs[i][j] > strs[i + 1][j]) {
                    count++;
                    break;
                }
            }
            if (i + 1 < (int)strs.size()) {
                continue;
            }
            for (int i = 0; i + 1 < (int)strs.size(); i++) {
                sorted[i] = sorted[i] || strs[i][j] < strs[i + 1][j];
            }
        }
        return count;
    }
};
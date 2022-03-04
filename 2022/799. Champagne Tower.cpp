class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> prev;
        double pd = poured;
        for (int i = 0; i <= query_row && pd > 0; i++) {
            vector<double> curr(i + 1);
            for (int j = 0; j <= i; j++) {
                if (i == query_row) {
                    if (i == 0) {
                        curr[j] = max(1.0, pd);
                    } else if (j == 0) {
                        curr[j] = min(1.0, prev[j] / 2);
                    } else if (j == i) {
                        curr[j] = min(1.0, prev[j - 1] / 2);
                    } else {
                        curr[j] = min(1.0, (prev[j - 1] + prev[j]) / 2);
                    }
                }
                else
                {
                    if (i == 0) {
                        curr[j] = max(pd - 1.0, 0.0);
                    } else if (j == 0) {
                        curr[j] = max(prev[j] / 2 - 1, 0.0);
                    } else if (j == i) {
                        curr[j] = max(prev[j - 1] / 2 - 1, 0.0);
                    } else {
                        curr[j] = max((prev[j - 1] + prev[j]) / 2 - 1, 0.0);
                    }
                    pd -= min(1.0, curr[j]);
                }
            }
            prev = curr;
        }

        if (prev.size() <= query_glass) {
            return 0;
        }

        return min(prev[query_glass], 1.0);
    }
};
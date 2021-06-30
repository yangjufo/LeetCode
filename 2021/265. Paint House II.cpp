class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int k = costs[0].size();
        vector<int> dp(k, 0);
        int prevFirst = 0, prevSecond = 0, currFirst = 0, currSecond = 1;
        for (int i = 0; i < costs.size(); i++) {
            vector<int> next(k, INT_MAX);
            for (int j = 0; j < costs[i].size(); j++) {
                next[j] = costs[i][j];
                if (prevFirst == j) {
                    next[j] += dp[prevSecond];
                } else {
                    next[j] += dp[prevFirst];
                }
                if (next[j] < next[currFirst]) {
                    currSecond = currFirst;
                    currFirst = j;
                } else if (j != currFirst && next[j] < next[currSecond]) {
                    currSecond = j;
                }                        
            }                        
            prevFirst = currFirst;
            prevSecond = currSecond;
            dp = next;        
        }
        
        return dp[prevFirst];
    }
};
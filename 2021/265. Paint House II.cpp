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

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        vector<int> dp(k, 0);
        int prevFirst = 0, prevSecond = 0, currFirst = 0, currSecond = 1;
        for (int i = 0; i < n; i++) {            
            vector<int> next(k, INT_MAX);
            for (int j = 0; j < k; j++) {
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


class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int k = costs[0].size(), min1 = 0, min2 = 0, index1 = -1;        
        for (int i = 0; i < costs.size(); i++) {
            int curr1 = INT_MAX, curr2 = INT_MAX, currIndex1 = -1, sum = 0;
            for (int j = 0; j < k; j++) {
                if (j != index1) {
                    sum = costs[i][j] + min1;
                } else {
                    sum = costs[i][j] + min2;
                }
                if (sum < curr1) {
                    currIndex1 = j;
                    curr2 = curr1;
                    curr1 = sum;
                } else if (sum < curr2) {
                    curr2 = sum;
                }
            }
            min1 = curr1;
            min2 = curr2;
            index1 = currIndex1;
        }
        return min(min1, min2);
    }
};
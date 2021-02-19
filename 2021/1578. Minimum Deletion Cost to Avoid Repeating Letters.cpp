class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int total = 0, maxCost = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && s[i] != s[i - 1]) {
                maxCost = 0;
            }
            total += min(maxCost, cost[i]);
            maxCost = max(maxCost, cost[i]);
        }
        
        return total;
    }
};
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

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int totalCost = 0, maxCost = 0, subCost = 0, dupCount = 0;
        for (int i = 0; i < s.length() || dupCount > 1; i++) {
            if (i > 0 && i < s.length() && s[i] == s[i - 1]) {
                dupCount++;
                maxCost = max(cost[i], maxCost);
                subCost += cost[i];
            } else {
                if (dupCount > 1) {
                    totalCost += subCost - maxCost;
                }
                dupCount = 1;
                if (i < s.length()) {
                    maxCost = cost[i];
                    subCost = cost[i];
                }                                                    
            }
        }
        return totalCost;
    }
};
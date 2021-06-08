class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), step1 = cost[1], step2 = cost[0];        
        for (int i =  2; i < n; i++) {
            int tmp = step1;
            step1 = min(step1, step2) + cost[i];
            step2 = tmp;
        }
        return min(step1, step2);
    }
};
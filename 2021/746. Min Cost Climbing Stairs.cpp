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

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1 = 0, prev2 = 0;
        for (int i = 0; i < cost.size(); i++) {
            int curr = min(prev1, prev2) + cost[i];
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev2, prev1);
    }
};
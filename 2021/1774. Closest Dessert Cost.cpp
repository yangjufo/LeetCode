class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = baseCosts[0];
        for (int i = 0; i < baseCosts.size(); i++) {            
            backtrack(toppingCosts, 0, 0, baseCosts[i], target, res);                        
        }
        return res;
    }
    
    void backtrack(vector<int>& toppingCosts, int start, int currCount, int sum, int target, int& res) {
        if (abs(sum - target) < abs(res - target) || (abs(sum - target) == abs(res - target) && sum < res)) {
            res = sum;
        }
        if (start >= toppingCosts.size()) return;
        backtrack(toppingCosts, start + 1, 0, sum, target, res);
        if (currCount == 0) {
            backtrack(toppingCosts, start, 1, sum + toppingCosts[start], target, res);
        } else {
            backtrack(toppingCosts, start + 1, 0, sum + toppingCosts[start], target, res);
        }
    }
};
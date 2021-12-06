class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        sort(position.begin(), position.end());
        int minCost = INT_MAX;
        for (int p : position) {
            int currCost = 0;
            for (int m : position) {                
                currCost += abs(p - m) % 2 == 0 ? 0 : 1;
            }
            minCost = min(minCost, currCost);
        }
        return minCost;
    }
};
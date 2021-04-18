class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for (int i = 0; i < costs.size() && coins >= costs[i]; i++) {
            count++;
            coins -= costs[i];
        }
        return count;
    }
};
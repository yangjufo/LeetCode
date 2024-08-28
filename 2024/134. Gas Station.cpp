class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0, currTank = 0, cand = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalTank += gas[i] - cost[i];
            currTank += gas[i] - cost[i];
            if (currTank < 0) {
                cand = (i + 1) % gas.size();
                currTank = 0;
            }
        }
        return totalTank >= 0 ? cand : - 1;
    }
};
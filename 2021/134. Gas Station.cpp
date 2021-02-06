class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int totalTank = 0, currTank = 0, startIndex = 0;
        for (int i = 0; i < n; i++) {
            totalTank += gas[i] - cost[i];
            currTank += gas[i] - cost[i];
            
            if (currTank < 0) {
                startIndex = (i + 1) % n;
                currTank = 0;
            }
        }
        return totalTank >= 0 ? startIndex : -1;
    }
};
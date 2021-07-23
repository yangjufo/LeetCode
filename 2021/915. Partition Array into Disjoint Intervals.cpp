class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> maxVals, minVals;
        maxVals = minVals = nums;
        for (int i = 1; i < nums.size(); i++) {
            maxVals[i] = max(maxVals[i], maxVals[i - 1]);
        }        
        for (int i = (int)nums.size() - 2; i >= 0; i--) {
            minVals[i] = min(minVals[i], minVals[i + 1]);
        }
        for (int i = 1; i < nums.size(); i++) {
            if (maxVals[i - 1] <= minVals[i]) {
                return i;
            }
        }
        return -1;
    }
};
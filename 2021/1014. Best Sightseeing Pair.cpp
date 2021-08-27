class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int leftMax = 0, res = 0;
        for (int i = 0; i < values.size(); i++) {
            res = max(values[i] - i + leftMax, res);
            leftMax = max(values[i] + i, leftMax);
        }        
        return res;
    }
};
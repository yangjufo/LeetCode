class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        int rightMax = 0;
        for (int i = heights.size() - 1; i >= 0; i--) {
            if (heights[i] > rightMax) {
                res.push_back(i);
            }
            rightMax = max(rightMax, heights[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
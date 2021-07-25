class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        int maxHeight = 0;
        for (int i = (int)heights.size() - 1; i >= 0; i--) {
            if (heights[i] > maxHeight) {
                res.push_back(i);
                maxHeight = heights[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
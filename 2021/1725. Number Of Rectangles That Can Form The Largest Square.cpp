class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int, int> count;
        int maxLen = 0;
        for (vector<int>& r : rectangles) {
            int side = min(r[0], r[1]);
            count[side]++;
            maxLen = max(maxLen, side);            
        }
        return count[maxLen];
    }
};
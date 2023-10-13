class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = min(rectangles[0][0], rectangles[0][1]);
        int count = 0;
        for (vector<int>& r : rectangles) {
            int currLen = min(r[0], r[1]);
            if (currLen > maxLen) {
                count = 1;
                maxLen = currLen;
            } else if (currLen == maxLen) {
                count++;
            }
        }
        return count;
    }
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int start = (int) sqrt(area);
        while (start > 0) {
            if (area % start == 0) {
                return {area / start, start};
            }
            start--;
        }
        return {area, 1};
    }
};
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int i = 0, count = 0;
        while (i < points.size()) {
            count++;
            int minEnd = points[i][1];
            while (i < points.size() && points[i][0] <= minEnd) {
                minEnd = min(points[i][1], minEnd);
                i++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int i = 0, count = 0;
        while (i < points.size()) {
            count++;
            int minEnd = points[i][1];
            while (i < points.size() && points[i][0] <= minEnd) {
                minEnd = min(points[i][1], minEnd);
                i++;
            }
        }
        return count;
    }
};

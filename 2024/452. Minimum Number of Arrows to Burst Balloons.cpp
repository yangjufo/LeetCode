class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& left, vector<int>& right) {
            return left[1] == right[1] ? left[0] < right[0] : left[1] < right[1];
        });
        int count = 1, prev = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= prev) {
                prev = min(points[i][1], prev);
            } else {
                prev = points[i][1];
                count += 1;
            }
        }
        return count;
    }
};
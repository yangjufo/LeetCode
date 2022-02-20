class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& left, vector<int>& right) {
            return left[0] == right[0] ? left[1] > right[1] : left[0] < right[0];
        });
        int curr = 0, removed = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= intervals[curr][0] && intervals[i][1] <= intervals[curr][1]) {
                removed++;
            } else {
                curr = i;
            }
        }
        return intervals.size() - removed;
    }
};
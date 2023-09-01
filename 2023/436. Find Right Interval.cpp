class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> starts, ends;
        for (int i = 0; i < intervals.size(); i++) {
            starts.push_back({intervals[i][0], i});
            ends.push_back({intervals[i][1], i});
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        vector<int> res(intervals.size());
        int i = 0, j = 0;
        while (i < starts.size() && j < ends.size()) {
            if (starts[i].first >= ends[j].first) {
                res[ends[j].second] = starts[i].second;
                j++;
            } else {
                i++;
            }
        }
        while (j < ends.size()) {
            res[ends[j].second] = -1;
            j++;
        }
        return res;
    }
};
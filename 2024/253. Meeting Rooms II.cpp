class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& left, vector<int>& right) {
            return left[0] == right[0] ? left[1] < right[1] : left[0] < right[0];
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < intervals.size(); i++) {
            if (!pq.empty() && intervals[i][0] >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};
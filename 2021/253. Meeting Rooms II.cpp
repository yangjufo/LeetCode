class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {return a[0] < b[0]; });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (vector<int>& interval : intervals) {
            if (minHeap.empty() || interval[0] < minHeap.top()) {
                minHeap.push(interval[1]);
            } else {
                minHeap.pop();
                minHeap.push(interval[1]);
            }
        }
        return minHeap.size();
    }
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return 0;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) { return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];});
        int last = intervals[0][1];
        int count = 0;
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < last) {
                last = min(intervals[i][1], last);
                count++;                
            } else {
                last = intervals[i][1];
            }
        }
        
        return count;
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& left, auto& right){
            return left[1] == right[1] ? left[0] < right[0] : left[1] < right[1];
        });        
        int index = 0, count = 0;        
        for (int i = 1; i < intervals.size(); i++) {            
            if (intervals[i][0] < intervals[index][1]) {
                count++;
            } else {
                index = i;
            }
        }
        return count;
    }
};
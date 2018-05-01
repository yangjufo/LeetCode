/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty())
            return vector<Interval>{newInterval};
        vector<Interval> res;
        int i;
        for(i = 0; i < intervals.size(); i++){
            if (intervals[i].end >= newInterval.start)
                break;
            res.push_back(intervals[i]);
        }
        if (i == intervals.size()){
            res.push_back(newInterval);
            return res;
        }
            
        if (intervals[i].start < newInterval.start)
            swap(newInterval, intervals[i]);
        res.push_back(newInterval);
        for(; i < intervals.size(); i++){
            if (res.back().end >= intervals[i].start)
                res.back().end = max(res.back().end, intervals[i].end);            
            else
                break;
        }
        for(; i < intervals.size();i++){
            res.push_back(intervals[i]);
        }
        return res;
    }
};
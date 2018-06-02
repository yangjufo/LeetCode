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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [](Interval x, Interval y){
            return x.start < y.start;
        });
        int count = 0;
        int i = 0;
        int j = 1;
        while (i < intervals.size() - 1&& j < intervals.size()){
            if (intervals[i].end > intervals[j].start){
                count++;                                
                if (intervals[j].end < intervals[i].end)
                    i = j;
                j++;
            }
            else{
                i = j;
                j++;
            }
        }    
        return count;
    }
};

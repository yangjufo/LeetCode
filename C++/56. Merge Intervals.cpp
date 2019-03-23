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
    template <typename T>
	struct cmp{
		bool operator()(const T &x, const T &y){
            if (x.start < y.start)
                return true;
            else if(x.start == y.start)
                return x.end < y.end;
            else
			    return false;
		}
	};
	
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty())
            return intervals;
		sort(intervals.begin(), intervals.end(), cmp<Interval>());
        vector<Interval> res;
        res.push_back(intervals[0]);
        int j = 0;
        for (int i = 1; i < intervals.size(); i++){
			if (res[j].start <= intervals[i].end && res[j].end >= intervals[i].start){
				Interval tmp = Interval(res[j].start, max(intervals[i].end, res[j].end));
				res.pop_back();
				res.push_back(tmp);				
			}
			else{
				res.push_back(intervals[i]);            
                j += 1;
            }
        }
		return res;
    }
};
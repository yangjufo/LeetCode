class SummaryRanges {
public:
    /** Initialize your data structure here. */
    set<int> starts;
    unordered_map<int, int> ends;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto iter = starts.upper_bound(val);
        if (starts.empty()
            || (ends[*prev(iter)] + 1 < val && (iter == starts.end() || val + 1 < *iter))
            || (iter == starts.begin() && *iter > val + 1)) {            
            starts.insert(val);
            ends[val] = val;
        } else {
            bool mergedPrev = false;
            if (iter != starts.begin() && ends[*prev(iter)] + 1 >= val) {
                ends[*prev(iter)] = max(ends[*prev(iter)], val);
                mergedPrev = true;
            }            
            if (iter != starts.end() && val + 1 >= *iter) {
                if (mergedPrev) {
                    ends[*prev(iter)] = ends[*iter];
                } else {
                    starts.insert(val);
                    ends[val] = ends[*iter];
                }
                ends.erase(*iter);
                starts.erase(iter);
            }            
        }        
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (int s : starts) {
            res.push_back({s, ends[s]});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
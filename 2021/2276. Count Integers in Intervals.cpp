class CountIntervals {
public:
    int total = 0;
    map<int, int> intervals;
    CountIntervals() {

    }

    void add(int left, int right) {
        auto start = intervals.lower_bound(left);
        if (start != intervals.begin() && prev(start)->second >= left) {
            start = prev(start);
        }
        auto end = intervals.upper_bound(right);
        for (auto i = start; i != end && i != intervals.end(); ) {
            left = min(left, i->first);
            right = max(right, i->second);
            total -= i->second - i->first + 1;
            auto n = next(i);
            intervals.erase(i);
            i = n;
        }
        intervals[left] = right;
        total += right - left + 1;
    }

    int count() {
        return total;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
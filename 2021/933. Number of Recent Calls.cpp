class RecentCounter {
public:
    deque<int> dq;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(!dq.empty() && dq.front() + 3000 < t) {
            dq.pop_front();
        }
        dq.push_back(t);
        return dq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
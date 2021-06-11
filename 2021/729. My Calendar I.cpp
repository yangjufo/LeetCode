class MyCalendar {
public:
    map<int, int> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (events.empty() || end < events.begin()->first || start > events.rbegin()->second) {            
            events[start] = end;
            return true;
        }            
        auto iter = events.upper_bound(start);
        if (start < prev(iter)->second || (iter != events.end() && end > iter->first)) {
            return false;
        }        
        events[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

class MyCalendar {
public:
    map<int, int> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {                
        auto iter = events.lower_bound(start);
        if (iter != events.end() && iter->first < end) return false; 
        if (iter != events.begin() && prev(iter)->second > start) return false;
        events[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

class MyCalendar {
public:
    set<int> eventStart;
    unordered_map<int, int> eventEnd;
    MyCalendar() {        
    }
    
    bool book(int start, int end) {
        auto iter = upper_bound(eventStart.begin(), eventStart.end(), start);
        if (iter != eventStart.begin() && eventEnd[*prev(iter)] > start) return false;
        if (iter != eventStart.end() && *iter < end) return false;
        eventStart.insert(start);
        eventEnd[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
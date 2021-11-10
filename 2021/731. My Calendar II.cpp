class MyCalendarTwo {
public:
    map<int, int> singleBook, doubleBook;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        if (!doubleBook.empty()) {
            auto iter = doubleBook.lower_bound(start);
            if ((iter != doubleBook.begin() && prev(iter)->second > start) ||
                (iter != doubleBook.end() && iter->first < end)) {
                return false;
            }
        }
        if (!singleBook.empty()) {
            auto iter = singleBook.lower_bound(start);
            while (iter != singleBook.begin()) {
                if (prev(iter)->second > start)
                {
                    doubleBook[start] = min(prev(iter)->second, end);
                }                
                iter--;
            } 
            iter = singleBook.lower_bound(start);
            while (iter != singleBook.end() && iter->first < end) {
                doubleBook[iter->first] = min(iter->second, end);
                iter++;
            }                     
        }   
        if (singleBook.find(start) == singleBook.end() || singleBook[start] < end) {
            singleBook[start] = end;
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
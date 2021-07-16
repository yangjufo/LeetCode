class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    int maxNumbers, index;
    unordered_set<int> slots;
    PhoneDirectory(int maxNumbers) {
        this->maxNumbers = maxNumbers;
        index = 0;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {        
        if (index < maxNumbers) {
            index++;
            return index-1;
        }
        if (!slots.empty()) {
            int res = *(slots.begin());
            slots.erase(slots.begin());
            return res;
        }   
        return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {        
        if (index <= number || slots.find(number) != slots.end()) return true;
        return false;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (index > number) {
            slots.insert(number);
        }        
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    vector<int> next;
    int pos;
    PhoneDirectory(int maxNumbers) {
        next.resize(maxNumbers, 0);
        for (int i = 0; i < maxNumbers; i++) {
            next[i] = (i + 1) % maxNumbers;
        }
        pos = 0;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (next[pos] == -1) return -1;
        int ret = pos;
        pos = next[pos];
        next[ret] = -1;
        return ret;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return next[number] != -1;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (next[number] != -1) return;
        next[number] = pos;
        pos = number;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
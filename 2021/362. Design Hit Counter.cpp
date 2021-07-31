class HitCounter {
public:
    deque<int> timeDeque;
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        timeDeque.push_back(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
         while (!timeDeque.empty() && timestamp - timeDeque.front() >= 300) {
            timeDeque.pop_front();
        }
        return timeDeque.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */

class HitCounter {
public:
    int hitCounter[300];
    int timestamps[300];
    /** Initialize your data structure here. */
    HitCounter() {
        fill(hitCounter, hitCounter + 300, 0);
        fill(timestamps, timestamps + 300, 0);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int index = timestamp % 300;
        if (timestamps[index] != timestamp) {
            timestamps[index] = timestamp;
            hitCounter[index] = 1;
        } else {
            hitCounter[index]++;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int hits = 0;
        for (int i = 0; i < 300; i++) {
            if (timestamp - timestamps[i] < 300) {
                hits += hitCounter[i];
            }
        }
        return hits;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */

class HitCounter {
public:
    vector<int> count, time;  
    /** Initialize your data structure here. */
    HitCounter() {
        count.resize(300, 0);
        time.resize(300, 0);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (count[timestamp % 300] > 0 && time[timestamp % 300] == timestamp) {
            count[timestamp % 300]++;
        } else {
            count[timestamp % 300] = 1;
            time[timestamp % 300] = timestamp;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int sum = 0;
        for (int i = 0; i < 300; i++) {
            if (count[i] > 0 && time[i] + 300 > timestamp) {
                sum += count[i];
            }
        }
        return sum;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
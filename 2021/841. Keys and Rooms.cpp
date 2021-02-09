class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        int count = 0;
        unordered_set<int> keys = {0};
        while (!keys.empty()) {
            unordered_set<int> newKeys;
            for (int key : keys) {
                visited[key] = true;                
                for (int room : rooms[key]) {                    
                    if (!visited[room]) {
                        newKeys.insert(room);
                    }
                }                                
            }
            keys = newKeys;
        }
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
};


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

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, 0);        
        stack<int> roomStack;
        roomStack.push(0);
        while (!roomStack.empty()) {
            int r = roomStack.top();
            roomStack.pop();
            visited[r] = true;
            for (int next : rooms[r]) {
                if (!visited[next]) {                    
                    roomStack.push(next);
                }
            }
        }
        
        for (bool v : visited) {
            if (!v) return false;
        }
        
        return true;
    }
};
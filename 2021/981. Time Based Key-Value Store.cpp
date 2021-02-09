class TimeMap {
public:
    unordered_map<string, vector<int>> keyTimeMap;
    unordered_map<string, unordered_map<int, string>> keyValueMap;
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {        
        keyTimeMap[key].push_back(timestamp);        
        keyValueMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (keyTimeMap.find(key) == keyTimeMap.end()) {
            return "";
        }
        int index = upper_bound((keyTimeMap[key]).begin(), (keyTimeMap[key]).end(), timestamp) - keyTimeMap[key].begin();               
        index--;      
        if (index < 0) {
            if (keyTimeMap[key][0] > timestamp) return "";
            index = 0;  
        }
        return keyValueMap[key][keyTimeMap[key][index]];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
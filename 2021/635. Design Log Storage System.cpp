class LogSystem {
public:
    map<string, int> logs;
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {        
        logs[timestamp] = id;
    }
    
    vector<int> retrieve(string start, string end, string granularity) {        
        string startKey, endKey;
        if (granularity == "Year") {
            startKey = start.substr(0, 4) + ":00:00:00:00:00";
            endKey = end.substr(0, 4) + ":12:31:23:59:59";
        } else if (granularity == "Month") {
            startKey = start.substr(0, 7) + ":00:00:00:00";
            endKey = end.substr(0, 7) + ":31:23:59:59";
        } else if (granularity == "Day") {
            startKey = start.substr(0, 10) + ":00:00:00";
            endKey = end.substr(0, 10) + ":23:59:59";
        } else if (granularity == "Hour") {
            startKey = start.substr(0, 13) + ":00:00";
            endKey = end.substr(0, 13) + ":59:59";
        } else if (granularity == "Minute") {
            startKey = start.substr(0, 16) + ":00";
            endKey = end.substr(0, 16) + ":59";
        } else if (granularity == "Second") {
            startKey = start;
            endKey = end;
        }
        auto startIter = logs.lower_bound(startKey), endIter = logs.upper_bound(endKey);
        vector<int> res;
        for (auto iter = startIter; iter != endIter; iter++) {
            res.push_back(iter->second);
        }
        return res;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
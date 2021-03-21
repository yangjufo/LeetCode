class UndergroundSystem {
public:    
    unordered_map<int, pair<string, int>> checkInTime;
    unordered_map<string, pair<int, int>> totalTime;    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInTime[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        totalTime[checkInTime[id].first + "#" + stationName].first += t - checkInTime[id].second;
        totalTime[checkInTime[id].first + "#" + stationName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return totalTime[startStation + "#" + endStation].first * 1.0 / totalTime[startStation + "#" + endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
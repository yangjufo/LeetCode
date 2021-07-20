class Solution {
public:
    int hours[4] = {1, 2, 4, 8}, minutes[6] = {1, 2, 4, 8, 16, 32};
    vector<vector<bool>> visited;
    vector<string> res;
    vector<string> readBinaryWatch(int turnedOn) {                
        visited.resize(12, vector<bool>(60, false));
        dfs(0, 0, 0, 0, turnedOn);
        sort(res.begin(), res.end());
        return res;
    }
    
    void dfs(int hour, int min, int hourIndex, int minIndex, int turnedOn) {        
        if (hour > 11 || min > 59 || visited[hour][min]) return;
        visited[hour][min] = true;
        if (turnedOn <= 0) {
            res.push_back({to_string(hour) + ":" + (min < 10 ? "0" : "") + to_string(min)});
            return;
        }
        for (int i = hourIndex; i < 4; i++) {            
            dfs(hour + hours[i], min, i + 1, minIndex, turnedOn - 1);
        }
        for (int i = minIndex; i < 6; i++) {
            dfs(hour, min + minutes[i], hourIndex, i + 1, turnedOn - 1);
        }
    }
    
};
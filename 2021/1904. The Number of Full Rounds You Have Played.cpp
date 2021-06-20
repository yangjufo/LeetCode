class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int startHour = stoi(startTime.substr(0, 2)), startMin = stoi(startTime.substr(3, 2));
        int endHour = stoi(finishTime.substr(0, 2)), endMin = stoi(finishTime.substr(3, 2));
        if (startHour > endHour || (startHour == endHour && startMin > endMin)) {
            endHour += 24;            
        }
        if (startMin > endMin) {
            endHour -= 1;
            endMin += 60;
        }
        return max(0, (endHour - startHour)) * 4 + (endMin / 15 - (startMin + 14) / 15);                
    }
};
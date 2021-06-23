class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int startHour = stoi(startTime.substr(0, 2)), startMin = startHour * 60 + stoi(startTime.substr(3, 2));
        int endHour = stoi(finishTime.substr(0, 2)), endMin = endHour * 60 + stoi(finishTime.substr(3, 2));
        if (endMin < startMin) {
            endMin += 24 * 60;
        }
        return max(0, (endMin / 15 - (startMin + 14) / 15));
    }
};
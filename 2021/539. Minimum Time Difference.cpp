class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int minDiff = 24 * 60;
        int lastHour = stoi(timePoints.back().substr(0, 2));
        int lastMin = stoi(timePoints.back().substr(3, 2));
        for (int i = 0; i < timePoints.size(); i++) {
            int currHour = stoi(timePoints[i].substr(0, 2));
            int currMin = stoi(timePoints[i].substr(3, 2));
            int diff = (currHour - lastHour) * 60 + (currMin - lastMin);
            if (i == 0) {
                diff += 24 * 60;
            }
            minDiff = min(diff, minDiff);
            lastHour = currHour;
            lastMin = currMin;
        }
        return minDiff;
    }
};

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int points[1440];
        memset(points, -1, sizeof(points));
        for (string time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int min = stoi(time.substr(3, 2));
            if (points[hour * 60 + min] != -1) return 0;
            points[hour * 60 + min] = 1;
        }
        
        int minDiff = 1440, firstDiff = 1440;
        int first = -1, prev = -1;
        for (int i = 0; i < 1440; i++) {            
            if (points[i] != -1) {                
                if (first == - 1) {
                    first = i;                    
                } else {
                    minDiff = min(minDiff, i - prev);                    
                    firstDiff = 1440 + first - i;
                }
                prev = i;
            }
        }
        
        return min(minDiff, firstDiff);
    }
};
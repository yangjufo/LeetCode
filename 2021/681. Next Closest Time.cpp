class Solution {
public:
    string nextClosestTime(string time) {
        int leftH = stoi(time.substr(0, 2)), leftM = stoi(time.substr(3, 2));
        unordered_set<int> digits = {leftH % 10, leftH / 10, leftM % 10, leftM / 10};
        int minDiff = INT_MAX;
        string res;
        for (int d1 : digits) {     
            if (d1 > 2) continue;
            for (int d2 : digits) {
                if (d1 == 2 && d2 > 3) continue;
                for (int d3 : digits) {
                    if (d3 > 5) continue;
                    for (int d4 : digits) {
                        int currDiff = timeDiff(leftH, leftM, d1 * 10 + d2, d3 * 10 + d4);
                        if (currDiff < minDiff && ((d1 * 10 + d2) != leftH || (d3 * 10 + d4) != leftM)) {
                            minDiff = currDiff;
                            res = (d1 == 0 ? "0" : to_string(d1)) + to_string(d2) + ":" + (d3 == 0 ? "0" : to_string(d3)) + to_string(d4);
                        }
                    }
                }
            }
        }
        return res.empty() ? time : res;
    }
    
    int timeDiff(int leftH, int leftM, int rightH, int rightM) {
        if (rightM < leftM) {
            rightH--;
        }
        return (rightH + 24 - leftH) % 24 * 60 + (rightM + 60 - leftM) % 60;        
    }
};
class Solution {
public:
    bool checkRecord(string s) {
        int absentCount = 0, lateCount = 0;
        for (int i = 0; i < s.length() && absentCount < 2 && lateCount < 3; i++) {
            if (s[i] == 'A') {
                absentCount++;
            }
            if (s[i] == 'L') {
                lateCount++;                
            } else {
                lateCount = 0;
            }
        }
        return absentCount < 2 && lateCount < 3;
    }
};
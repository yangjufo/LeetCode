class Solution {
public:
    string maximumTime(string time) {
        string res = time;
        if (time[0] == '?') {
            if (time[1] == '?') {
                res[0] = '2'; 
                res[1] = '3';
            } else if (time[1] > '3') {
                res[0] = '1';
            } else {
                res[0] = '2';
            }
        } else if (time[1] == '?') {
            if (time[0] <= '1') {
                res[1] = '9';
            } else{
                res[1] = '3';
            }
        }        
        if (time[3] == '?') {
            res[3] = '5';
        }
        if (time[4] == '?') {
            res[4] = '9';
        }
        return res;
    }
};
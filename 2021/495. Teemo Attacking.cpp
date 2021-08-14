class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0, start = 0, end = 0;
        for (int t : timeSeries) {        
            if (t > end) {
                total += end - start;
                start = t;                
            }
            end = t + duration;
        }
        return total + end - start;
    }
};
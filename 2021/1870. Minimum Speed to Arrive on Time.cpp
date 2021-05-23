class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {        
        int left = 1, right = 10'000'001;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!check(dist, mid, hour)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left > 10'000'000 ? -1 : left; 
    }
    
    bool check(vector<int>& dist, int speed, double hour) {
        long total = 0;
        for (int i = 0; i + 1 < dist.size(); i++) {
            total += (dist[i] + speed - 1) / speed;
        }                
        return dist.back() * 1.0 / speed + total <= hour;
    }
    
    
};
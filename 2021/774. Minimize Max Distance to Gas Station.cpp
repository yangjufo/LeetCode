class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        int maxDis = 0;
        for (int i = 1; i < stations.size(); i++) {
            maxDis = max(maxDis, stations[i] - stations[i - 1]);
        }
        double left = 0, right = maxDis;
        while (right - left > 1e-6) {
            double mid = left + (right - left) / 2;
            if (canPlace(stations, k, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
    
    bool canPlace(vector<int>& stations, int k, double distance) {
        for (int i = 1; i < stations.size() && k >= 0; i++) {
            if (stations[i] - stations[i - 1] > distance) {
                k -= (int)((stations[i] - stations[i - 1]) / distance);
            }
        }
        return k >= 0;
    }
};
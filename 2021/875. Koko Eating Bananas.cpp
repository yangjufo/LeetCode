class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0;
        int maxVal = 0;
        for (int p : piles) {
            sum += p;
            maxVal = max(maxVal, p);
        }
        long long left = (sum + h - 1) / h, right = maxVal;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canEat(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    bool canEat(vector<int>& piles, int h, long long k) {
        for (int i = 0; i < piles.size() && h >= 0; i++) {            
            h -= (piles[i] + k - 1) / k;            
        }    
        return h >= 0;
    }
};
class Solution {
public:
    bool canEat(vector<int>& piles, int k, int h) {
        for (int i = 0; i < piles.size() && h >= 0; i++) {
            h -= (piles[i] + k - 1) / k;
        }
        return h >= 0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = INT_MAX;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canEat(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
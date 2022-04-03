class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        sort(candies.begin(), candies.end(), greater<int>());
        int left = 1, right = candies[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (can(candies, mid, k)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return can(candies, left, k) ? left : left - 1;
    }

    bool can(vector<int>& candies, int target, long long k) {
        for (int i = 0; i < candies.size() && k > 0 && candies[i] >= target; i++) {
            k -= candies[i] / target;
        }
        return k <= 0;
    }
};
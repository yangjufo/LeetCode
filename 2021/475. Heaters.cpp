class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int j = 0, minRadius = 0;
        for (int i = 0; i < houses.size(); i++) {
            while (j + 1 < heaters.size() && (heaters[j] == heaters[j + 1] || abs(houses[i] - heaters[j]) > abs(houses[i] - heaters[j + 1]))) {
                j++;
            }
            minRadius = max(minRadius, abs(houses[i] - heaters[j]));
        }
        return minRadius;
    }
};
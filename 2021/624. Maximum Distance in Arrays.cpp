class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        pair<int, int> min1 = {INT_MAX, 0}, min2 = {INT_MAX, 0}, max1 = {INT_MIN, 0}, max2 = {INT_MIN, 0};
        for (int i = 0; i < arrays.size(); i++) {
            if (arrays[i][0] < min1.first) {
                min2 = min1;
                min1 = {arrays[i][0], i};
            } else if (arrays[i][0] < min2.first) {
                min2 = {arrays[i][0], i};
            }
            
            if (arrays[i].back() > max1.first) {
                max2 = max1;
                max1 = {arrays[i].back(), i};
            } else {
                max2 = {arrays[i].back(), i};
            }
        }
        if (max1.second == min1.second) {
            return max(max1.first - min2.first, max2.first - min1.first);
        }
        return max1.first - min1.first;
    }
};
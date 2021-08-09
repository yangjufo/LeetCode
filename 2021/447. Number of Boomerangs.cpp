class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int, int> distanceMap;
        int total = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                distanceMap[getDistance(points[i], points[j])]++;
            }            
            for (auto& iter : distanceMap) {
                total += iter.second * (iter.second - 1);
            }
            distanceMap.clear();
        }        
        return total;
    }
    
    int getDistance(vector<int>& left, vector<int>& right) {
        int dx = left[0] - right[0], dy = left[1] - right[1];
        return dx * dx + dy * dy;
    }
};
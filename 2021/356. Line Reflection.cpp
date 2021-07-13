class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_set<string> pointSet;
        int minX = INT_MAX, maxX = INT_MIN;
        for (vector<int>& p : points) {
            minX = min(minX, p[0]);
            maxX = max(maxX, p[0]);
            pointSet.insert(to_string(p[0]) + "#" + to_string(p[1]));
        }
        int sum = minX + maxX;
        for (auto& p : pointSet) {
            string target = to_string(sum - stoi(p.substr(0, p.find("#")))) + "#" + p.substr(p.find("#") + 1);
            if (pointSet.find(target) == pointSet.end()) {
                return false;
            }
        }
        return true;
    }       
};
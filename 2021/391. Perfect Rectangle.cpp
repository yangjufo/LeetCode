class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {        
        int x1 = INT_MAX, y1 = INT_MAX, a1 = INT_MIN, b1 = INT_MIN, area = 0;
        unordered_map<string, int> count;
        for (vector<int>& r : rectangles) {
            x1 = min(r[0], x1);
            y1 = min(r[1], y1);
            a1 = max(r[2], a1);
            b1 = max(r[3], b1);
            
            count[buildKey(r[0], r[1])]++;
            count[buildKey(r[0], r[3])]++;
            count[buildKey(r[2], r[3])]++;
            count[buildKey(r[2], r[1])]++;
            area += (r[2] - r[0]) * (r[3] - r[1]);
        }
        
        unordered_set<string> recs;
        for (auto& iter : count) {
            if (iter.second % 2 != 0) {
                recs.insert(iter.first);
            }
        }
        if (recs.size() != 4 || recs.find(buildKey(x1, y1)) == recs.end() || recs.find(buildKey(x1, b1)) == recs.end() || recs.find(buildKey(a1, b1)) == recs.end() || recs.find(buildKey(a1, y1)) == recs.end()) return false;
        return area == (a1 - x1) * (b1 - y1);
    }
            
    string buildKey(int x, int y) {
        return to_string(x) + "#" + to_string(y);
    }
};
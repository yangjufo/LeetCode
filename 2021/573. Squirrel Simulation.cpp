class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int maxSaveDis = INT_MIN, totalDis = 0;
        for (vector<int>& nut : nuts) {
            totalDis += (abs(nut[0] - tree[0]) + abs(nut[1] - tree[1])) * 2;
            maxSaveDis = max(maxSaveDis, abs(nut[0] - tree[0]) + abs(nut[1] - tree[1]) - abs(nut[0] - squirrel[0]) - abs(nut[1] - squirrel[1]));
        }
        return totalDis - maxSaveDis;
    }
};
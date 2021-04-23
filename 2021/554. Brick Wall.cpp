class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> breaks;
        for (int i = 0; i < wall.size(); i++) {
            int pos = 0;
            for (int j = 0; j + 1 < wall[i].size(); j++) {
                pos += wall[i][j];                
                breaks[pos] += 1;
            }                        
        }
        int maxEmpty = 0;
        for (auto& iter : breaks) {
            maxEmpty = max(maxEmpty, iter.second);
        }
        return (int)wall.size() - maxEmpty;
    }
};
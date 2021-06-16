class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> indexes(3);
        for (int i = 0; i < colors.size(); i++) {
            indexes[colors[i] - 1].push_back(i);
        }
        vector<int> res;
        for (vector<int>& query : queries) {
            if (indexes[query[1] - 1].empty()) {
                res.push_back(-1);
                continue;
            }
            auto it = upper_bound(indexes[query[1] - 1].begin(), indexes[query[1] - 1].end(), query[0]);        
            
            if (it == indexes[query[1] - 1].end() || (it != indexes[query[1] - 1].begin() && *it - query[0] > query[0] - *prev(it))) {
                res.push_back(query[0] - *prev(it));  
            } else {            
                res.push_back(*it - query[0]);
            }            
        }            
        return res;
    }
};
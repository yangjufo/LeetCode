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

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> colorIndexes(4);
        for (int i = 0; i < colors.size(); i++) {
            colorIndexes[colors[i]].push_back(i);
        }        
        vector<int> res;
        for (vector<int>& q : queries) {
            if (colorIndexes[q[1]].empty()) {
                res.push_back(-1);
            } else {
                auto iter = upper_bound(colorIndexes[q[1]].begin(), colorIndexes[q[1]].end(), q[0]);
                if (iter == colorIndexes[q[1]].end() || (iter != colorIndexes[q[1]].begin() && *iter - q[0] > q[0] - *prev(iter))) {
                    res.push_back(q[0] - *prev(iter));
                } else {
                    res.push_back(*iter - q[0]);
                }
            }
        }
        return res;
    }
};
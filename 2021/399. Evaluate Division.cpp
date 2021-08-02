class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> eMap;        
        for (int i = 0; i < equations.size(); i++) {
            eMap[equations[i][0]][equations[i][1]] = values[i];
            eMap[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        vector<double> res;
        unordered_set<string> visited;
        for (vector<string>& q : queries) {
            visited.insert(q[0]);
            res.push_back(dfs(eMap, q[0], q[1], 1.0, visited));
            visited.erase(q[0]);
        }
        return res;
    }
    
    double dfs(unordered_map<string, unordered_map<string, double>>& eMap, string start, string end, double curr, unordered_set<string>& visited) {
        if (eMap.find(start) == eMap.end()) return -1.0;
        for (auto& iter :eMap[start]) {
            if (iter.first == end) {
                return curr * iter.second;
            }
            if (visited.find(iter.first) == visited.end()) {
                visited.insert(iter.first);
                double next = dfs(eMap, iter.first, end, curr * iter.second, visited);
                visited.erase(iter.first);
                if (next > 0) {
                    return next;
                }                
            }             
        }
        return -1.0;
    }
};

class Solution {
public:
    unordered_map<string, unordered_map<string, double>> eMap;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < values.size(); i++) {
            eMap[equations[i][0]][equations[i][1]] = values[i];
            eMap[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        unordered_set<string> visited;
        vector<double> res;
        for (vector<string>& q : queries) {
            visited.insert(q[0]);
            res.push_back(dfs(visited, q[0], q[1], 1.0));
            visited.erase(q[0]);
        }
        return res;
    }
    
    double dfs(unordered_set<string>& visited, string start, string end, double curr) {
        if (eMap.find(start) == eMap.end()) return -1.0;
        for (auto& iter : eMap[start]) {
            if (iter.first == end) {
                return curr * iter.second;
            }
            if (visited.find(iter.first) == visited.end()) {
                visited.insert(iter.first);
                double next = dfs(visited, iter.first, end, curr * iter.second);
                visited.erase(iter.first);
                if (next > 0) {
                    return next;
                }
            }
        }
        return -1.0;
    }
};
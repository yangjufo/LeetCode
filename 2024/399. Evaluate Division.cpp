class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> edges;
        for (int i = 0; i < equations.size(); i++) {
            edges[equations[i][0]][equations[i][1]] = values[i];
            edges[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
        vector<double> res;
        unordered_set<string> visited;
        for (auto& q : queries) {
            visited.insert(q[0]);
            res.push_back(dfs(edges, visited, q[0], q[1], 1.0));
            visited.erase(q[0]);
        }
        return res;
    }

    double dfs(unordered_map<string, unordered_map<string, double>>& edges,
               unordered_set<string>& visited, const string& start,
               const string& end, double curr) {
        if (edges.find(start) == edges.end()) {
            return -1;
        }
        for (const auto& [next, value] : edges[start]) {
            if (next == end) {
                return curr * value;
            }
            if (visited.find(next) != visited.end()) {
                continue;
            }
            visited.insert(next);
            double ans = dfs(edges, visited, next, end, curr * value);
            visited.erase(next);
            if (ans > 0) {
                return ans;
            }
        }
        return -1;
    }
};
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> graph;
        for (vector<string>& p : paths) {
            graph[p[0]] = p[1];
        }
        string city = paths[0][0];
        while (graph.find(city) != graph.end()) {
            city = graph[city];
        }
        return city;
    }
};
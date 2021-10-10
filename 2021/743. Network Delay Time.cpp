class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> timeMap(n + 1, vector<int>(n + 1, -1));
        for (vector<int>& t : times) {
            timeMap[t[0]][t[1]] = t[2];
        }
        vector<int> visited(n + 1, false);
        auto comparator = [](pair<int, int>& left, pair<int, int>& right) {
            return left.second > right.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(comparator);        
        pq.push({k, 0});
        int res = 0;
        while (!pq.empty()) {
            int node = pq.top().first, dis = pq.top().second;
            pq.pop();
            if (visited[node]) {
                continue;
            }   
            visited[node] = true;
            res = dis;
            for (int i = 1; i <= n; i++) {                
                if (timeMap[node][i] >= 0) {
                    pq.push({i, dis + timeMap[node][i]});
                }                
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) return -1;
        }
        return res;
    }
};
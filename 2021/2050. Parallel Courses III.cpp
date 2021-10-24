class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> degrees(n + 1, 0);
        unordered_map<int, vector<int>> rMap;
        for (vector<int>& re : relations) {
            degrees[re[1]]++;
            rMap[re[0]].push_back(re[1]);
        }
        auto comparator = [](pair<int, int>& left, pair<int, int>& right){
            return left.second > right.second;
        };         
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(comparator);
        for (int i = 1; i <= n; i++) {
            if (degrees[i] == 0) {
                pq.push({i, time[i - 1]});
            }
        }
        int t = 0;
        while (!pq.empty()) {
            int c = pq.top().first;
            t = pq.top().second;
            pq.pop();
            for (int next : rMap[c]) {
                degrees[next]--;
                if (degrees[next] == 0) {
                    pq.push({next, t + time[next - 1]});
                }
            }            
        }        
        return t;
    }
};
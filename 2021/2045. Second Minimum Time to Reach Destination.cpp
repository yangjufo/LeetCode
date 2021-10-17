class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> edgeMap;
        for (vector<int>& edge : edges) {
            edgeMap[edge[0]].push_back(edge[1]);
            edgeMap[edge[1]].push_back(edge[0]);
        }        
        auto comparator = [](pair<int, int>& left, pair<int, int>& right) {
          return left.second > right.second;  
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(comparator);
        vector<vector<int>> nodeTimes(n + 1);
        pq.push({1, 0}); 
        nodeTimes[0].push_back(0);
        int minTime = -1;        
        while (!pq.empty() && nodeTimes[n].size() < 2) {
            int node = pq.top().first, currTime = pq.top().second;
            pq.pop();            
            if ((currTime / change) % 2 == 1) {
                currTime = (currTime / change + 1) * change;
            }
            for (int next : edgeMap[node]) {  
                if (nodeTimes[next].size() < 2) {
                    if (nodeTimes[next].empty() || nodeTimes[next][0] != currTime + time) {
                        nodeTimes[next].push_back(currTime + time);
                        pq.push({next, currTime + time});
                    }                    
                }                
            }
        }
        return nodeTimes[n][1];
    }
};
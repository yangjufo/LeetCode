class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        unordered_map<int, unordered_map<int, int>> edgeMap, rEdgeMap;
        for (auto& e : edges) {
            if (edgeMap.find(e[0]) == edgeMap.end() || edgeMap[e[0]].find(e[1]) == edgeMap[e[0]].end() || edgeMap[e[0]][e[1]] > e[2]) {
                edgeMap[e[0]][e[1]] = e[2];
                rEdgeMap[e[1]][e[0]] = e[2];
            }
        }
        vector<long long> m1(n, -1), m2(n, -1), md(n, -1);
        search(m1, src1, edgeMap);
        search(m2, src2, edgeMap);
        search(md, dest, rEdgeMap);

        long long res = -1;
        for (int i = 0; i < n; i++) {
            if (m1[i] == -1 || m2[i] == -1 || md[i] == -1) {
                continue;
            }
            if (res == -1 || m1[i] + m2[i] + md[i] < res) {
                res = m1[i] + m2[i] + md[i];
            }
        }
        return res;
    }

    void search(vector<long long>& mem, int src, unordered_map<int, unordered_map<int, int>>& edgeMap) {
        auto comparator = [](pair<int, long long>& left, pair<int, long long>& right) {
            return  left.second > right.second;
        };
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(comparator)> pq(comparator);
        mem[src] = 0;
        pq.push({src, 0});
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            for (auto& next : edgeMap[top.first]) {
                if (mem[next.first] == -1 || mem[next.first] > top.second + next.second) {
                    mem[next.first] = top.second + next.second;
                    pq.push({next.first, top.second + next.second});
                }
            }
        }
    }
};
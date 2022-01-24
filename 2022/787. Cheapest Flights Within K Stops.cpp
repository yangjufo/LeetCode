class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, unordered_map<int, int>> fMap;
        for (vector<int>& f : flights) {
            fMap[f[0]][f[1]] = f[2];
        }
        queue<pair<int, int>> pq;
        pq.push({0, src});
        unordered_map<int, int> pMap;
        pMap[src] = 0;
        int stop = -1;
        int minPrice = INT_MAX;
        while (!pq.empty() && stop <= k) {
            stop++;
            int size = pq.size();
            for (int i = 0; i < size; i++) {
                int price = pq.front().first, node = pq.front().second;
                pq.pop();
                if (node == dst) {
                    minPrice = min(minPrice, price);
                }
                for (auto& iter : fMap[node]) {
                    if (pMap.find(iter.first) == pMap.end() || pMap[iter.first] > iter.second + price) {
                        pMap[iter.first] = iter.second + price;
                        pq.push({iter.second + price, iter.first});
                    }
                }
            }
        }

        return minPrice == INT_MAX ? -1 : minPrice;
    }
};
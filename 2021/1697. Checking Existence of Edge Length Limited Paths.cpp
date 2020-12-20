class Solution {
public:
    class DSU {    
        vector<int> parents, ranks;

        public:
        DSU(int n) {
            parents.resize(n);
            ranks.resize(n);
            for (int i = 0; i < n; i++) {
                parents[i] = i;
            }
        }

        int find(int x) {
            return parents[x] == x ? x : find(parents[x]);
        }
        
        bool merge(int x, int y) {
            int parentX = find(x), parentY = find(y);
            if (parentX != parentY) {
                if (ranks[parentX] < ranks[parentY]) {
                    parents[parentX] = parentY;
                } else {
                    parents[parentY] = parentX;
                    ranks[parentX] += (ranks[parentX] == ranks[parentY]) ? 1 : 0;
                }                
                return true;
            }
            return false;
        }
    };
    
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU dsu(n);
        
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }
        
        sort(queries.begin(), queries.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
        sort(edgeList.begin(), edgeList.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
        
        int i = 0;
        vector<bool> result(queries.size(), 0);
        for (vector<int>& query : queries) {
            while (i < edgeList.size() && edgeList[i][2] < query[2]) {
                dsu.merge(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            
            result[query[3]] = dsu.find(query[0]) == dsu.find(query[1]);
        }
        
        return result;
        
    }
};
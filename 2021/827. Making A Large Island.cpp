class Solution {
public:
    vector<int> parents, ranks, sizes;    
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                parents.push_back(i * n + j);
                ranks.push_back(0);
                sizes.push_back(grid[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    int row = i + directions[k][0], col = j + directions[k][1];
                    if (row < 0 || row >= n || col < 0 || col >= n || grid[row][col] == 0) {
                        continue;
                    }
                    merge(i * n + j, row * n + col);
                }
            }
        }        
        int maxSize = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxSize = max(maxSize, sizes[find(i * n + j)]);
                if (grid[i][j] == 1) continue;                
                unordered_set<int> ps;
                for (int k = 0; k < 4; k++) {
                    int row = i + directions[k][0], col = j + directions[k][1];                    
                    if (row < 0 || row >= n || col < 0 || col >= n || grid[row][col] == 0) {
                        continue;
                    }                    
                    ps.insert(find(row * n + col));
                }                
                int size = 1;
                for (auto p : ps) {
                    size += sizes[p];
                }
                maxSize = max(maxSize, size);
            }
        }
        return maxSize;        
    }
    
    int find(int x) {
        if (x != parents[x]) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    void merge(int x, int y) {
        int pX = find(x), pY = find(y);
        if (pX != pY) {
            if (ranks[pX] < ranks[pY]) {
                parents[pX] = pY;
                sizes[pY] += sizes[pX];
            } else {
                parents[pY] = pX;
                sizes[pX] += sizes[pY];
                if (ranks[pX] == ranks[pY]) {
                    ranks[pX]++;
                }
            }
        }
    }        
};
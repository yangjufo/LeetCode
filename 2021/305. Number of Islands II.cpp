class Solution {
public:
    vector<int> parents, ranks;
    int count, directions[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {        
        vector<int> res = {1};
        count = 1;        
        parents.resize(m * n, 0);
        ranks.resize(m * n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                parents[i * n + j] = i * n + j;
            }
        }
        vector<vector<bool>> islands(m, vector<bool>(n, false));
        islands[positions[0][0]][positions[0][1]] = true;
        for (int i = 1; i < positions.size(); i++) {
            if (islands[positions[i][0]][positions[i][1]] == false) {
                count++;
                int row = positions[i][0], col = positions[i][1];
                islands[positions[i][0]][positions[i][1]] = true;
                for (int j = 0; j < 4; j++) {
                    int newRow = row + directions[j][0], newCol = col + directions[j][1];
                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || islands[newRow][newCol] == false) {
                        continue;
                    }
                    merge(row * n + col, newRow * n + newCol);
                }
            }
            res.push_back(count);
        }
        return res;
    }
    
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    void merge(int x, int y) {
        int pX = find(x), pY = find(y);
        if (pX != pY) {
            count--;
            if (ranks[pX] > ranks[pY]) {
                parents[pY] = parents[pX];
            } else {
                parents[pX] = parents[pY];
                if (ranks[pX] == ranks[pY]) {
                    ranks[pY]++;
                }
            }
        }
    }
};
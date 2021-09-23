class Solution {
public:
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = (m == 0) ? 0 : grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, 0));
        vector<vector<int>> reach(m, vector<int>(n, 0));
        int totalBuildings = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    totalBuildings++;
                    bfs(grid, dis, reach, i, j, m, n);
                }
            }
        }
        
        
        int res = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && reach[i][j] == totalBuildings) {
                    res = (res == -1) ? dis[i][j] : min(res, dis[i][j]);
                }
            }
        }
        return res;                
    }
    
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& dis, vector<vector<int>>& reach, int x, int y, int m, int n) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> posQueue;
        posQueue.push({x, y});        
        int currDis = 1;
        while (!posQueue.empty()) {
            int size = posQueue.size();
            for (int i = 0; i < size; i++) {
                vector<int> pos = posQueue.front();
                posQueue.pop();

                for (int j = 0; j < 4; j++) {
                    int nX = pos[0] + directions[j][0], nY = pos[1] + directions[j][1];
                    if (nX < 0 || nX >= m || nY < 0 || nY >= n || grid[nX][nY] != 0 || visited[nX][nY]) continue;   
                    dis[nX][nY] += currDis;                
                    reach[nX][nY]++;       
                    visited[nX][nY] = true;
                    posQueue.push({nX, nY});
                }
            }
            currDis++;
        }        
    }
};

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();

        int mindist = INT_MAX;
        vector<vector<int>> distance(m, vector<int>(n,0));
        
        int target = 0;
        
        vector<vector<int>> dir {{1,0},{0,1}, {-1,0},{0,-1}};
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != 1) continue;
                
                mindist = INT_MAX;
                queue<pair<int,int>> q;
                q.emplace(i,j);
                int level = 1;
                while(!q.empty())
                {
                    int sz = q.size();
                    for(int k = 0; k < sz; k++)
                    {
                        auto curr = q.front();
                        q.pop();
                        for(auto &d : dir)
                        {
                            int a = curr.first+d[0];
                            int b = curr.second+d[1];
                            
                            if(a == m || b == n || a == -1 || b == -1) continue;
                            
                            if(grid[a][b] == target)
                            {
                                q.emplace(a,b);
                                grid[a][b]--;
                                distance[a][b] += level;
                                mindist = min(mindist, distance[a][b]);
                            }
                        }
                    }
                    level++;
                }
                target--;
            }
        }
        
        return mindist == INT_MAX ? -1 : mindist;
        
    }
};

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();

        int mindist = INT_MAX;
        vector<vector<int>> distance(m, vector<int>(n,0));
        
        int target = 0;
        
        vector<vector<int>> dir {{1,0},{0,1}, {-1,0},{0,-1}};
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != 1) continue;
                
                mindist = INT_MAX;
                queue<pair<int,int>> q;
                q.emplace(i,j);
                int level = 1;
                while(!q.empty())
                {
                    int sz = q.size();
                    for(int k = 0; k < sz; k++)
                    {
                        auto curr = q.front();
                        q.pop();
                        for(auto &d : dir)
                        {
                            int a = curr.first+d[0];
                            int b = curr.second+d[1];
                            
                            if(a == m || b == n || a == -1 || b == -1) continue;
                            
                            if(grid[a][b] == target)
                            {
                                q.emplace(a,b);
                                grid[a][b]--;
                                distance[a][b] += level;
                                mindist = min(mindist, distance[a][b]);
                            }
                        }
                    }
                    level++;
                }
                target--;
            }
        }
        
        return mindist == INT_MAX ? -1 : mindist;
        
    }
};
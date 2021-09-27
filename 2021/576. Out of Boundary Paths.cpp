const int mod = 1e9 + 7, moves[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int findPaths(int m, int n, int maxMove, int r, int c) {
	auto outOfBounds = [&](int m, int n, int r, int c){return r < 0 || r >= m || c < 0 || c >= n;};
	uint dp[50][50][2]{};        
	for(int M = 1; M <= maxMove; M++)
		for(int i = 0; i < m; i++) 
			for(int j = 0, k; j < n; j++) 
				for(k = 0, dp[i][j][M & 1] = 0; k < 4; k++) 
					if(outOfBounds(m, n, i + moves[k][0], j + moves[k][1])) dp[i][j][M & 1]++;
					else dp[i][j][M & 1] += dp[i + moves[k][0]][j + moves[k][1]][(M-1) & 1] % mod;
	return dp[r][c][maxMove & 1] % mod;
}

class Solution {
public:
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<array<uint, 2>>> dp(m, vector<array<uint, 2>>(n, {0, 0}));
        for (int move = 1; move <= maxMove; move++) {
            for (int row = 0; row < m; row++) {
                for (int col = 0; col < n; col++) {
                    dp[row][col][move & 1] = 0;
                    for (int d = 0; d < 4; d++) {                        
                        int newRow = row + directions[d][0], newCol = col + directions[d][1];
                        if (isOut(m, n, newRow, newCol)) {                            
                            dp[row][col][move & 1] += 1;                            
                        } else {
                            dp[row][col][move & 1] += dp[newRow][newCol][(move - 1) & 1] % mod;
                        }
                    }                    
                }
            }
        }        
        return dp[startRow][startColumn][maxMove & 1] % mod;
    }
    
    bool isOut(int m, int n, int row, int col) {
        return row < 0 || row >= m || col < 0 || col >= n;
    }
};
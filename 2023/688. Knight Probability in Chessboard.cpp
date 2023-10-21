class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<int>> dir{{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
        vector<vector<double>> count(n, vector<double>(n, 0));
        count[row][column] = 1;
        for (int s = 0; s < k; s++){
            vector<vector<double>> tmp(n, vector<double>(n, 0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int v = 0; v < 8; v++) {
                        int x = i + dir[v][0], y = j + dir[v][1];
                        if (x < 0 || x >= n || y < 0 || y >= n) {
                            continue;
                        }
                        tmp[i][j] += count[x][y];
                    }
                }
            }
            count = tmp;
        }
        double total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                total += count[i][j];
            }
        }
        return total / pow(8, k);
    }
};
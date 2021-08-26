class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {        
        if (image[sr][sc] != newColor) {
            dfs(image, sr, sc, newColor, image[sr][sc]);
        }        
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {        
        image[sr][sc] = newColor;
        for (int i = 0; i < 4; i++) {
            int newRow = sr + directions[i][0], newCol = sc + directions[i][1];
            if (newRow < 0 || newRow >= image.size() || newCol < 0 || newCol >= image[0].size() || image[newRow][newCol] != oldColor) {
                continue;
            }
            dfs(image, newRow, newCol, newColor, oldColor);
        }
    }
};
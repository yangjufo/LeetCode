class Solution {
public:
    int directions[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> res(img.size(), vector<int>(img[0].size(), 0));
        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[0].size(); j++) {
                int sum = img[i][j], count = 1;
                for (int d = 0; d < 8; d++) {
                    int row = i + directions[d][0], col = j + directions[d][1];
                    if (row < 0 || row >= img.size() || col < 0 || col >= img[0].size()) {
                        continue;
                    }
                    sum += img[row][col];
                    count++;
                }
                res[i][j] = sum / count;
            }
        }
        return res;
    }
};
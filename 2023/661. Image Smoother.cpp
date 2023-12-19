class Solution {
public:
    int dirs[9][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {0, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> smooth(img.size(), vector<int>(img[0].size(), 0));
        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[0].size(); j++) {
                int sum = 0, count = 0;
                for (int d = 0; d < 9; d++) {
                    int r = i + dirs[d][0], c = j + dirs[d][1];
                    if (r < 0 || r >= img.size() || c < 0 || c >= img[0].size()) {
                        continue;
                    }
                    count += 1;
                    sum += img[r][c];
                }
                smooth[i][j] = sum / count;
            }
        }
        return smooth;
    }
};
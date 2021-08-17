class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        vector<int> rowCount(picture.size(), 0), colCount(picture[0].size(), 0);
        for (int i = 0; i < picture.size(); i++) {
            for (int j = 0; j < picture[0].size(); j++) {
                if (picture[i][j] == 'B') {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < picture.size(); i++) {
            for (int j = 0; j < picture[0].size(); j++) {
                if (picture[i][j] == 'B' && rowCount[i] == 1 && colCount[j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};
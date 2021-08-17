class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        vector<string> pStrs;
        vector<int> rowCount(picture.size(), 0);
        vector<vector<int>> colIndex(picture[0].size());
        for (int i = 0; i < picture.size(); i++) {
            string rowStr;
            for (int j = 0; j < picture[0].size(); j++) {
                rowStr += picture[i][j];
                if (picture[i][j] == 'B') {
                    rowCount[i]++;
                    colIndex[j].push_back(i);
                }
            }
            pStrs.push_back(rowStr);
        }
        int count = 0;
        for (int i = 0; i < picture.size(); i++) {
            for (int j = 0; j < picture[0].size(); j++) {
                if (picture[i][j] == 'B' && rowCount[i] == target && colIndex[j].size() == target) {                    
                    bool valid = true;
                    for (int r : colIndex[j]) {
                        if (pStrs[r] != pStrs[i]) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
class Solution {
public:
    int countPoints(string rings) {
        vector<vector<bool>> counts(10, vector<bool>(3, false));
        for (int i = 0; i < rings.size(); i += 2) {
            if (rings[i] == 'R') {
                counts[rings[i + 1] - '0'][0] = true;
            } else if (rings[i] == 'B') {
                counts[rings[i + 1] - '0'][1] = true;
            } else if (rings[i] == 'G') {
                counts[rings[i + 1] - '0'][2] = true;
            }
        }
        int res = 0;
        for (int i = 0; i < 10; i++) {
            if (counts[i][0] == true && counts[i][1] == true && counts[i][2] == true) {
                res++;
            }
        }
        return res;
    }
};
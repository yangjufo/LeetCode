class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size()) {
            if (firstList[i][0] > secondList[j][1]) {
                j += 1;
            } else if (firstList[i][1] < secondList[j][0]) {
                i += 1;
            } else {
                res.push_back({max(firstList[i][0], secondList[j][0]),
                               min(firstList[i][1], secondList[j][1])});
                if (firstList[i][1] < secondList[j][1]) {
                    i += 1;
                } else {
                    j += 1;
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> res(1, triangle[0][0]);
        for (int i = 1; i < triangle.size(); i++) {
            vector<int> tmp(triangle[i].size(), 0);
            for (int j = 0; j < triangle[i].size(); j++) {
                tmp[j] = triangle[i][j];
                if (j == 0) {
                    tmp[j] += res[j];
                } else if (j == triangle[i].size() - 1){
                    tmp[j] += res[j - 1];
                }
                else {
                    tmp[j] += min(res[j - 1], res[j]);
                }
            }
            res = tmp;
        }
        int ans = res[0];
        for (int i = 0; i < res.size(); i++) {
            ans = min(ans, res[i]);
        }
        return ans;
    }
};
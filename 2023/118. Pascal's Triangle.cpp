class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};
        for (int i = 1; i < numRows; i++) {
            vector<int> curr = res.back();
            for (int j = 1; j < i; j++) {
                curr[j] = res.back()[j] + res.back()[j - 1];
            }
            curr.push_back(1);
            res.push_back(curr);
        }
        return res;
    }
};
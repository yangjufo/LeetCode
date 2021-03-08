class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};
        for (int i = 2; i <= numRows; i++) {
            vector<int> row = {1};
            for (int j = 1; j < res.back().size(); j++) {
                row.push_back(res.back()[j - 1] + res.back()[j]);
            }
            row.push_back(1);
            res.push_back(row);
        }        
        return res;
    }
};
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

class Solution {
public:
    vector<vector<int>> generate(int numRows) {        
        vector<vector<int>> res(numRows);        
        for (int i = 1; i <= numRows; i++) {
            res[i - 1].push_back(1);
            for (int j = 1; i > 1 && j < res[i - 2].size(); j++) {
                res[i - 1].push_back(res[i - 2][j] + res[i - 2][j - 1]);
            }
            if (i > 1) {
                res[i - 1].push_back(1);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};
        for (int i = 2; i <= numRows; i++) {
            res.push_back(res.back());            
            res.back().push_back(1);              
            for (int j = i - 2; j >= 1; j--) {
                res.back()[j] += res.back()[j - 1];
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};        
        for (int i = 1; i <= rowIndex; i++) {
            vector<int> newRow = {1};
            for (int j = 1; j < row.size(); j++) {
                newRow.push_back(row[j - 1] + row[j]);
            }
            newRow.push_back(1);
            row = newRow;
        }
        return row;
    }
};

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = vector<int>(rowIndex + 1, 1);
        for (int i = 1; i < rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                row[j] += row[j - 1];
            }
        }
        return row;
    }
};

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        for (int i = 2; i <= rowIndex + 1; i++) {                     
            res.push_back(1);
            for (int j = i - 2; j >= 1; j--) {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};
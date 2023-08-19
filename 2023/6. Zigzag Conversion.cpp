class Solution {
public:
    string convert(string s, int numRows) {
         vector<vector<char>> rows(numRows);
         int count = 0, flag = 1;
         for (char c : s) {
             rows[count].push_back(c);
             count = (count + flag) % numRows;
             if (count == 0 || count == numRows - 1) {
                 flag = -flag;
             }
         }
         string res;
         for (vector<char>& row : rows) {
             for (char c : row) {
                 res += c;
             }
         }
         return res;
    }
};
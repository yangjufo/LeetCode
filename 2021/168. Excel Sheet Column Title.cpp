class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber > 26) {
            res += (columnNumber - 1) % 26 + 'A';    
            columnNumber = (columnNumber - 1) / 26;
        }
        res += (columnNumber - 1) % 26 + 'A';
        reverse(res.begin(), res.end());
        return res;
    }
};
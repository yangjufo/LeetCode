class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0, open = 0, close = 0;
        for (char c : s) {
            if (c == '(') {
                open++;
            } else {
                close++;
            }
            if (open < close) {
                count += close - open;
                open = close = 0;
            } else {
                open -= close;
                close = 0;
            }
        }        
        return count + open;
    }
};
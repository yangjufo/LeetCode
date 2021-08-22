class Solution {
public:    
    bool judgeCircle(string moves) {
        int row = 0, col = 0;
        for (char c : moves) {
            switch(c) {
                case 'U':
                    row--;
                    break;
                case 'D':
                    row++;
                    break;
                case 'L':
                    col--;
                    break;
                case 'R':
                    col++;
                    break;
            }
        }
        return row == 0 && col == 0;
    }
};
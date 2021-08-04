class Solution {
public:
    bool isRobotBounded(string instructions) {
        int row = 0, col = 0, dx = 0, dy = 1, ox, oy;
        for (char c : instructions) {            
            switch (c) {
                case 'G':
                    row += dx;
                    col += dy;
                    break;
                case 'L':
                    ox = dx, oy = dy;
                    dx = (ox != 0 ? 0 : (oy == 1 ? -1 : 1));
                    dy = (oy != 0 ? 0 : (ox == 1 ? 1 : -1));                    
                    break;
                case 'R':            
                    ox = dx, oy = dy;
                    dx = (ox != 0 ? 0 : (oy == 1 ? 1 : -1));
                    dy = (oy != 0 ? 0 : (ox == 1 ? -1 : 1));
                    break;
            }            
        }
        return ((row == 0 && col == 0) || dx != 0 || dy != 1);
    }
};
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir_set[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int cx, cy, dir;
        cx = cy = dir = 0; 
        for (int i = 0; i < 4; i++) {
            for (char c : instructions) {                
                if (c == 'G') {
                    cx += dir_set[dir][0];
                    cy += dir_set[dir][1];
                }
                else if (c == 'L')
                    dir = (dir + 1) % 4;
                else
                    dir = (dir - 1 + 4) % 4;
                if (i != 0 && cx == 0 && cy == 0) 
                    return true;
            }
        }
        return false;
    }
};
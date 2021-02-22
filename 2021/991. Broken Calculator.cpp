class Solution {
public:
    int brokenCalc(int X, int Y) {
        int res = 0;
        while (Y > X) {
            res += 1;
            if ((Y & 0x1) == 1) {
                Y += 1;
            } else {
                Y >>= 1;
            }
        }
        return res + X - Y;
    }
};
class Solution {
public:
    int minSwaps(string s) {
        int zCount0 = 0, zCount1 = 0, oCount0 = 0, oCount1 = 0;
        for (int i = 0; i < s.length(); i++) {
            if ((i & 0x1) == 1) {
                if (s[i] == '0') {
                    oCount0++;
                } else {
                    zCount1++;
                }
            } else {
                if (s[i] == '0') {
                    zCount0++;
                } else {
                    oCount1++;
                }
            }
        }
        if (zCount0 != zCount1 && oCount0 != oCount1) {
            return -1;
        }
        if (zCount0 == zCount1 && oCount0 == oCount1) {
            return min(zCount0, oCount0);
        } else if (zCount0 == zCount1) {
            return zCount0;
        } else {
            return oCount0;
        }
    }
};
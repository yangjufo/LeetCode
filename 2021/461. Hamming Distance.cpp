class Solution {
public:
    int hammingDistance(int x, int y) {
        int total = 0, t = x ^ y;        
        while (t > 0) {
            total++;
            t = t & (t - 1);
        }             
        return total;
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        int total = 0;
        while (x > 0 && y > 0) {
            total += (x & 0x1) == (y & 0x1) ? 0 : 1;
            x >>= 1;
            y >>= 1;
        }        
        while (x > 0) { 
            total += 1;
            x = x & (x - 1);
        }
        while (y > 0) {
            total += 1;
            y = y & (y - 1);
        }
        return total;
    }
};
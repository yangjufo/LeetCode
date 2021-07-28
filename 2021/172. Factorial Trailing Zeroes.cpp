class Solution {
public:
    int trailingZeroes(int n) {
        int zeroCount = 0;        
        while (n > 0) {
            n /= 5;
            zeroCount += n;
        }
        return zeroCount;
    } 
};

class Solution {
public:
    int trailingZeroes(int n) {
        vector<int> count2(n + 1, 0), count5(n + 1, 0);
        int total2 = 0, total5 = 0;
        for (int i = 1; 2 * i <= n; i++) {
            count2[2 * i] = 1 + count2[i];
            total2 += count2[2 * i];
        }
        for (int i = 1; 5 * i <= n; i++) {
            count5[5 * i] = 1 + count5[i];
            total5 += count5[5 * i];
        }        
        return min(total2, total5);
    }
};
class Solution {
public:
    int mod = 1000000000 + 7;
    int minNonZeroProduct(int p) {
        long long end = (long long)pow(2, p) - 1;
        long long res = end % mod;
        end = ((long long)pow(2, p) - 2) % mod;
        res = res * myPow(end, ((long long)pow(2, p - 1) - 1)) % mod;
        return res;        
    }
    
    int myPow(long long x, long long n) {                
        long long res = 1;
        for (long long i = n; i != 0; i /= 2) {
            if (i & 0x1) res = (x * res) % mod;
            x = (x * x) % mod;
        }
        
        return res;
    }
};
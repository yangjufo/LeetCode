class Solution {
public:
    int mod = 1'000'000'007;    
    int countGoodNumbers(long long n) {
        return myPow(5, (n + 1) / 2) % mod * myPow(4, n/ 2) % mod;
    }     
    
    long long myPow(long long x, long long n) {
        long long res = 1;
        for (long long i = n; i != 0; i /= 2) {
            if (i & 0x1) res = (res * x) % mod;
            x = (x * x) % mod;
        }
        
        return res;
    }
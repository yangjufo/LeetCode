class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
        int cnt = 0;
        for (int i = left; i <= right; i++) {
            int bits = 0;
            for (int n = i; n; n >>= 1)
                bits += n & 1;
            cnt += primes.count(bits);
        }
        return cnt;
    }
};
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        a %= 1337;
        if (b.empty()) return 1;
        vector<int> halfB;
        int rem = 0;
        for (int i = 0; i < b.size(); i++) {
            int curr = (rem * 10 + b[i]) / 2;
            rem = (rem * 10 + b[i]) % 2;
            if (!(i == 0 && curr == 0)) {
                halfB.push_back(curr);
            }
        }
        int half = superPow(a, halfB) % 1337, res = (half * half) % 1337;
        if ((rem & 0x1) == 1) {
            res = (res * a) % 1337;
        }
        return res;
    }
};

class Solution {
public:
    int mod = 1337;
    int helper(int a, int b) {
        a %= mod;
        if (b == 0) return 1;
        int half = helper(a, b / 2) % mod;
        return ((half * half) % mod * ((b & 0x1) == 1 ? a : 1)) % mod;
    }
    
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int lastDigit = b.back();
        b.pop_back();
        return (helper(superPow(a, b), 10) * helper(a, lastDigit)) % mod;
    }
};

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (a % 1337 == 0) return 0; // this line could also be removed
        int p = 0;
        for (int i : b) p = (p * 10 + i) % 1140;
        if (p == 0) p += 1140;
        return power(a, p, 1337);
    }
    int power(int x, int n, int mod) {
        int ret = 1;
        for (x %= mod; n; x = x * x % mod, n >>= 1) if (n & 1) ret = ret * x % mod;
        return ret;
    }
};


class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            if (isValid(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
    
    bool isValid(int n) {
        int n2 = n;
        while (n > 0) {
            if (n % 10 == 0 || n2 % (n % 10) != 0) return false;
            n /= 10;
        }
        return true;
    }
};
class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> nums;
        for (int i = 0; i <= (int) sqrt(c); i++) {
            nums.insert(i * i);
            if (nums.find(c - i * i) != nums.end()) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            double b = sqrt(c - a * a);
            if (b == (int) b) {
                return true;
            }
        }
        return false;
    }
};
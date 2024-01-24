class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while (n != 1) {
            set.insert(n);
            int next = 0;
            while (n != 0) {
                next += (n % 10) * (n % 10);
                n /= 10;
            }
            n = next;
            if (set.find(n) != set.end()) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length(), total = 0;
        int curr = 1;
        while (n > 0) {
            total += (n > 8 ? 8 : n) * curr;
            n -= 8;
            curr += 1;
        }
        return total;
    }
};
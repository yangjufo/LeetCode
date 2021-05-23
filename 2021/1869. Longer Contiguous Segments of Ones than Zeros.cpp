class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones = 0, zeros = 0, lo = 0, lz = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                zeros++;
                ones = 0;
            } else {
                ones++;
                zeros = 0;
            }
            lo = max(ones, lo);
            lz = max(zeros, lz);
        }
        return lo > lz;
    }
};
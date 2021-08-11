class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int oneCount = 0, prev = 0;
        for (char c : s) {
            if (c == '1') {
                oneCount++;
            } else {
                prev = min(prev + 1, oneCount);
            }
        }
        return prev;
    }
};
class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;
        for (char c : n) {
            int d = c - '0';
            maxDigit = max(d, maxDigit);
        }
        return maxDigit;        
    }
};
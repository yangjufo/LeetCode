class Solution {
public:
    string maxValue(string n, int x) {
        bool neg = (n[0] == '-');
        int i = (neg ? 1 : 0);
        while (i < n.length() && ((neg && n[i] <= (x + '0')) || (!neg && n[i] >= (x + '0')))) {
            i++;
        }        
        return n.substr(0, i) + string(1, x + '0') + n.substr(i);
    }
};
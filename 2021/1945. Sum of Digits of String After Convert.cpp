class Solution {
public:
    int getLucky(string s, int k) {
        string digits;
        for (char c : s) {
            digits += to_string((c - 'a' + 1));
        }
        int res = 0;
        for (char c : digits) {
            res += c - '0';
        }
        for (int i = 1; i < k; i++) {
            int next = 0;
            for (char c : to_string(res)) {
                next += c - '0';
            }            
            res = next;
        }
        return res;
    }
};
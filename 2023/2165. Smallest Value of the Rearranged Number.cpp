class Solution {
public:
    long long smallestNumber(long long num) {
        if (num < 0 ) {
            string ns = to_string(-num);
            sort(ns.begin(), ns.end(), [](char l, char r) {
                return l > r;
            });
            return -stoll(ns);
        }
        string ns = to_string(num);
        char mc = '9' + 1;
        for (char c : ns) {
            if (c != '0' && c < mc) {
                mc = c;
            }
        }
        if (mc > '9') {
            return 0;
        }
        string res;
        string rs;
        for (char c : ns) {
            if (c == mc && res.empty()) {
                res += c;
            } else {
                rs += c;
            }
        }
        sort(rs.begin(), rs.end(), [](char l, char r) {
            return l < r;
        });
        res += rs;
        return stoll(res);
    }
};
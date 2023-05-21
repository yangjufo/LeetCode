class Solution {
public:
    bool check(string& sn, int n, int i, int l, int sum) {
        if (l == 0) {
            return i == sn.length() && sum == n;
        }
        for (int k = 1; i + k + l - 1 <= sn.length(); k++) {
            if (check(sn, n, i + k, l - 1, sum + stoi(sn.substr(i, k)))) {
                return true;
            }
        }
        return false;
    }
    bool same(int n) {
        std::string sn = to_string(n * n);
        for (int i = 0; i <= sn.length(); i++) {
            if (check(sn, n, 0, i, 0)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            if (same(i)) {
                sum += i * i;
            }
        }
        return sum;
    }
};
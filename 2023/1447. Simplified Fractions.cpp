class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (gcd(i, j) == 1) {
                    res.push_back(to_string(j) + "/" + to_string(i));
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> counts;
        for (int d : deck) {
            counts[d]++;
        }
        int X = -1;
        for (auto& iter : counts) {
            if (X == -1) {
                X = iter.second;
            } else {
                X = gcd(X, iter.second);
            }
        }
        return X >= 2;
    }
};
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<string, int> count;
        for (auto& rect : rectangles) {
            int div = gcd(rect[0], rect[1]);
            count[to_string(rect[0] / div) + "#" + to_string(rect[1] / div)]++;
        }
        long long res = 0;
        for (auto& iter : count) {
            res += (long long)iter.second * (iter.second - 1) / 2;
        }
        return res;
    }
};
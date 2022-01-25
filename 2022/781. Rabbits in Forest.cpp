class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> counts;
        for (int a : answers) {
            counts[a]++;
        }
        int res = 0;
        for (auto& iter : counts) {
            if (iter.first == 0) {
                res += iter.second;
                continue;
            }
            res += iter.second / (iter.first + 1) * (iter.first + 1);
            res += iter.second % (iter.first + 1) == 0 ? 0 : iter.first + 1;
        }
        return res;
    }
};
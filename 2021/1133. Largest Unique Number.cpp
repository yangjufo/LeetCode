class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        int res = -1;
        unordered_map<int, int> count;
        for (int a : A) {
            count[a]++;
        }
        for (auto& iter : count) {
            if (iter.second == 1 && iter.first > res) {
                res = iter.first;
            }
        }
        return res;
    }
};
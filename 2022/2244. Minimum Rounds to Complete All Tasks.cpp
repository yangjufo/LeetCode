class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> tm;
        for (int t : tasks) {
            tm[t]++;
        }
        int count = 0;
        for (auto& iter : tm) {
            if (iter.second < 2) {
                return -1;
            }
            count += (iter.second + 2) / 3;
        }
        return count;
    }
};
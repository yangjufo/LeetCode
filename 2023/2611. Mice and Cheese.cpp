class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        map<int, vector<int>> diffs;
        for (int i = 0; i < reward1.size(); i++) {
            diffs[reward1[i] - reward2[i]].push_back(i);
        }
        int total = 0, eaten = 0;
        for (auto iter = diffs.begin(); iter != diffs.end(); iter++) {
            for (int i = 0; i < iter->second.size(); i++) {
                total += (eaten < (reward1.size() - k)) ? reward2[iter->second[i]] :reward1[iter->second[i]];
                eaten++;
            }
        }
        return total;
    }
};
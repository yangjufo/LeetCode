class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> res(k, 0);        
        unordered_map<int, unordered_set<int>> uam;
        for (vector<int>& log : logs) {
            uam[log[0]].insert(log[1]);
        }
        for (auto& iter : uam) {
            res[(int)iter.second.size() - 1]++;
        }
        return res;
    }
};
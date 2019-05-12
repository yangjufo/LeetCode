class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> ans(N, 0);
        vector<unordered_set<int>> conns(N + 1, unordered_set<int>{});
        for (vector<int> p : paths) {
            conns[p[0]].insert(p[1]);
            conns[p[1]].insert(p[0]);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < 5; j++) {
                int work = true;
                for (int g : conns[i + 1]) {
                    if (ans[g - 1] == j) {
                        work = false;
                        break;
                    }               
                }
                if (work == true) {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<bool>> visited;
    bool canCross(vector<int>& stones) {
        visited.resize(stones.size(), vector<bool>(2000));
        return dfs(stones, 0, 1);
    }
    
    bool dfs(vector<int>& stones, int index, int units) {
        if (index + 1 >= stones.size()) return true;
        if (units <= 0 || visited[index][units]) return false;
        visited[index][units] = true;
        int next = index + 1;
        while (next < stones.size() && stones[index] + units != stones[next]) {
            next++;
        }                   
        if (next >= stones.size()) {
            return false;
        }
        return dfs(stones, next, units) || dfs(stones, next, units - 1) || dfs(stones, next, units + 1);
    }
};

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> steps;
        for (int n : stones) {
            steps[n] = {};
        }
        steps[0].insert(0);
        for (int i = 0; i < stones.size(); i++) {
            for (int j : steps[stones[i]]) {
                for (int k = j - 1; k <= j + 1; k++) {
                    if (k > 0 && steps.find(stones[i] + k) != steps.end()) {
                        steps[stones[i] + k].insert(k);
                    }
                }
            }
        }
        return !steps[stones.back()].empty();
    }
};
class Solution {
public:
    unordered_map<string, vector<bool>> visited;
    unordered_map<string, vector<string>> paths;
    int total = 0;
    vector<string> findItinerary(vector<vector<string>>& tickets) {               
        for (vector<string> t : tickets) {
            paths[t[0]].push_back(t[1]);
            visited[t[0]].push_back(false);
            total += 1;
        }        
        for (auto& iter : paths) {
            sort(iter.second.begin(), iter.second.end());
        }
        vector<string> res;
        dfs(visited, paths, "JFK", 0, res);
        return res;
    }
    
    int dfs(unordered_map<string, vector<bool>>& visited, unordered_map<string, vector<string>>& paths, string curr, int count, vector<string>& res) {  
        res.push_back(curr);                
        for (int i = 0; i < paths[curr].size(); i++) {
            if (!visited[curr][i]) {
                visited[curr][i] = true;
                if (dfs(visited, paths, paths[curr][i], count + 1, res) >= total) {
                    return total;
                }
                visited[curr][i] = false;
            }
        }
        if (count < total) {
            res.pop_back();
        }        
        return count;
    }
};
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

class Solution {
public:
    vector<string> res;
    unordered_map<string, map<string, int>> edges;
    vector<string> findItinerary(vector<vector<string>>& tickets) {        
        for (vector<string>& t : tickets) {
            edges[t[0]][t[1]]++;            
        }        
        res.push_back("JFK");
        dfs("JFK", tickets.size(), 0);
        return res;
    }
    
    bool dfs(string curr, int total, int count) {        
        for (auto& iter : edges[curr]) {
            if (iter.second > 0) {
                iter.second--;
                res.push_back(iter.first);
                if (dfs(iter.first, total, count + 1)) {
                    return true;
                }                    
                res.pop_back();
                iter.second++;
            }
        }
        return count >= total;
    }
};
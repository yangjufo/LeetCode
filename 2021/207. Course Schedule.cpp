class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degrees(numCourses, 0);        
        unordered_map<int, vector<int>> edges;
        for (auto const& pre : prerequisites) {
            degrees[pre[0]] += 1;
            edges[pre[1]].push_back(pre[0]);
        }
        while (true) {
            int curr = 0;
            while (curr < numCourses && degrees[curr] != 0) {
                curr++;
            }      
            if (curr >= numCourses) {
                for (int d : degrees) {
                    if (d > 0) return false;
                }
                return true;
            }
            degrees[curr] = -1;
            for (int node : edges[curr]) {
                degrees[node]--;                
            }            
        }        
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> edges;
        for (auto const& pre : prerequisites) {
            edges[pre[1]].push_back(pre[0]);
        }            
        unordered_set<int> visited, checked;
        
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(edges, i, visited, checked)) return false;
        }
        return true;
    }
    
    bool dfs(unordered_map<int, vector<int>>& edges, int start, unordered_set<int>& visited, unordered_set<int>& checked) {
        if (checked.count(start)) return true;
        if (visited.count(start)) return false;
        visited.insert(start);
        for (int node : edges[start]) {
            if(!dfs(edges, node, visited, checked))
                return false;            
        }
        visited.erase(start);
        checked.insert(start);
        return true;
    }
};


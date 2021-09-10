class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<vector<int>> pathQueue;
        pathQueue.push({0});
        vector<vector<int>> res;
        while (!pathQueue.empty()) {            
            vector<int> currPath = pathQueue.front();
            pathQueue.pop();
            for (int neigh : graph[currPath.back()]) {                
                currPath.push_back(neigh);
                if (neigh == graph.size() - 1) {
                    res.push_back(currPath);
                } else {
                    pathQueue.push({currPath});
                }                
                currPath.pop_back();
            }
        }
        return res;
    }
};
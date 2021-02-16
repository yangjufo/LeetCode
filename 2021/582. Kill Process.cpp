class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {        
        unordered_map<int, vector<int>> children;
        for (int i = 0; i < ppid.size(); i++) {   
            if (ppid[i] == 0) continue;
            children[ppid[i]].push_back(pid[i]);
        }
                        
        vector<int> killed;
        
        queue<int> killQueue;
        killQueue.push(kill);        
        while (!killQueue.empty()) {
            int curr = killQueue.front();
            killQueue.pop();
            killed.push_back(curr);
            for (int child : children[curr]) {      
                killQueue.push(child);
            }
        }
        return killed;
    }
};
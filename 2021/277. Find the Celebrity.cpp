/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> candidates;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            dfs(n, i, candidates, visited);
        }
        for (int c : candidates) {
            bool everyKnows = true;
            for (int i = 0; i < n; i++) {
                if (c != i && !knows(i, c)) {
                    everyKnows = false;
                    break;
                }
            }
            if (everyKnows) return c;
        }
        return -1;
    }
    
    void dfs(int n, int curr, vector<int>& candidates, vector<bool>& visited) {
        if (visited[curr]) return;
        visited[curr] = true;
        bool knowOthers = false;
        for (int i = 0; i < n; i++) {
            if (i != curr && knows(curr, i)) {                
                knowOthers = true;                
                dfs(n, i, candidates, visited);                
                break;
            }
        }
        if (!knowOthers) candidates.push_back(curr);
    }
};

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        
        for (int i = 0; i < n; i++) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (i != candidate && (knows(candidate, i) || !knows(i, candidate))) {
                return -1;
            }
        }
        
        return candidate;
    }
};
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {        
        vector<bool> visited(10000, false);
        for (string& d : deadends) {
            visited[stoi(d)] = true;
        }
        if (visited[0]) return -1;
        visited[0] = true;
        queue<int> keys;
        keys.push(0);
        int step = -1, targetInt = stoi(target);
        int adds[] = {10000, 1000, 100, 10, 1};
        while (!keys.empty()) {
            int size = keys.size();
            step += 1;
            for (int i = 0; i < size; i++) {                
                int curr = keys.front();
                keys.pop();
                if (curr == targetInt) return step;
                for (int j = 1; j < 5; j++) {
                    int next = (curr / adds[j - 1] * adds[j - 1]) + (curr % adds[j - 1] + adds[j - 1] + adds[j]) % adds[j - 1];
                    if (!visited[next]) {
                        visited[next] = true;
                        keys.push(next);
                    }
                    next = (curr / adds[j - 1] * adds[j - 1]) + (curr % adds[j - 1] + adds[j - 1] - adds[j]) % adds[j - 1];
                    if (!visited[next]) {
                        visited[next] = true;
                        keys.push(next);
                    }
                }                                
            }
        }
        return -1;
    }    
    
};
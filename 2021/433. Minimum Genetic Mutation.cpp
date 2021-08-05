class Solution {
public:
    char genes[4] = {'A', 'C', 'G', 'T'};
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, bool> visited;
        for (string& b : bank) {
            visited[b] = false;
        }
        visited[start] = false;
        queue<string> sQueue;
        sQueue.push(start);
        int step = -1;
        while (!sQueue.empty()) {
            step++;
            int size = sQueue.size();
            for (int i = 0; i < size; i++) {
                string curr = sQueue.front();
                visited[curr] = true;
                sQueue.pop();
                if (curr == end) {
                    return step;
                }
                for (int j = 0; j < curr.size(); j++) {
                    int tmp = curr[j];
                    for (char c : genes) {
                        curr[j] = c;
                        if (visited.find(curr) != visited.end() && visited[curr] == false) {
                            sQueue.push(curr);
                        }                        
                    }
                    curr[j] = tmp;
                }
            }
        }
        return -1;
    }
};
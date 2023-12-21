class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.find("0000") != visited.end()) {
            return -1;
        }
        queue<string> queue;
        queue.push("0000");
        int step = 0;
        while (!queue.empty()) {
            int size = queue.size();
            for (int i= 0; i < size; i++) {
                string curr = queue.front();
                queue.pop();
                if (curr == target) {
                    return step;
                }
                for (int j = 0; j < 4; j++) {
                    char tmp = curr[j];
                    if (tmp == '0') {
                        curr[j] = '9';
                    } else {
                        curr[j] = tmp - 1;
                    }
                    if (visited.find(curr) == visited.end()) {
                        visited.insert(curr);
                        queue.push(curr);
                    }
                    if (tmp == '9') {
                        curr[j] = '0';
                    } else {
                        curr[j] = tmp + 1;
                    }
                    if (visited.find(curr) == visited.end()) {
                        visited.insert(curr);
                        queue.push(curr);
                    }
                    curr[j] = tmp;
                }
            }
            step += 1;
        }
        return -1;
    }
};
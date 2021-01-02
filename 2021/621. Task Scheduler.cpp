class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.empty()) return 0;
        
        unordered_map<char, int> taskCountMap;
        for (char t : tasks) {
            taskCountMap[t]++;
        }
        vector<int> counts;
        for (auto const & iter : taskCountMap) {
            counts.push_back(iter.second);
        }
        sort(counts.begin(), counts.end(), [](int a, int b) {return a > b;});
        
        
        int slots = (counts[0] - 1) * n;
        int total = slots + counts[0];
        for (int i = 1; i < counts.size(); i++) {
            if (slots > 0) {
                if (counts[i] == counts[0]) {
                    total += 1;
                    slots -= counts[0] - 1;
                } else {
                    slots -= counts[i];
                }
                if (slots < 0) total += -slots;
            } else {
                total += counts[i];
            }            
        }
        
        return total;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int taskCount[26];
        fill(begin(taskCount), end(taskCount), 0);
        int maxCount = 0;
        int maxTaskNumber = 0;
        for (char task : tasks) {
            int t = task - 'A';
            taskCount[t]++;
            if (taskCount[t] == maxCount) {
                maxTaskNumber++;
            }
            if (taskCount[t] > maxCount) {
                maxCount = taskCount[t];
                maxTaskNumber = 1;
            }
        }
                
        
        int slots = (maxCount - 1) * (n - maxTaskNumber + 1);
        int remTasks = tasks.size() - maxCount * maxTaskNumber;
        return tasks.size() + max(0, slots - remTasks);
    }
};
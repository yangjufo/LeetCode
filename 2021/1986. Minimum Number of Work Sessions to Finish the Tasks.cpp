class Solution {
public:
    vector<vector<int>> mem;
    int minSessions(vector<int>& tasks, int sessionTime) {
        mem.resize((int) pow(2, tasks.size()), vector<int>(sessionTime + 1, -1));
        int expected = 0;
        for (int i = 0; i < tasks.size(); i++) {
            expected |= (1 << i);
        }
        return backtrack(tasks, 0, expected, sessionTime, sessionTime) + 1;
    }
    
    int backtrack(vector<int>& tasks, int done, int expected, int sessionTime, int leftTime) {
        if (done == expected) {
            return 0;
        }        
        if (mem[done][leftTime] >= 0) {
            return mem[done][leftTime];
        }        
        int minCount = 15;
        for (int i = 0; i < tasks.size(); i++) {
            if ((done & (1 << i)) == 0) {
                done |= (1 << i);
                if (tasks[i] <= leftTime) {
                    minCount = min(backtrack(tasks, done, expected, sessionTime, leftTime - tasks[i]), minCount);
                }                
                minCount = min(backtrack(tasks, done, expected, sessionTime, sessionTime - tasks[i]) + 1, minCount);
                done &= ~(1 << i);
            }
        }       
        mem[done][leftTime] = minCount;
        return mem[done][leftTime];
    }
    
};
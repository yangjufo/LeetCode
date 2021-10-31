class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<bool> visited(1001, false);
        if (goal >= 0 && goal <= 1000) {
            visited[goal] = true;
        } 
        queue<int> nq;
        nq.push(goal);
        int step = -1;
        while (!nq.empty()) {
            step++;
            int size = nq.size();
            for (int i = 0; i < size; i++) {
                goal = nq.front();
                nq.pop();
                if (goal == start) {
                    return step;
                }            
                for (int n : nums) {
                    if (goal + n >= 0 && goal + n <= 1000 && !visited[goal + n]) {
                        nq.push(goal + n);
                        visited[goal + n] = true;
                    }
                    if (goal - n >= 0 && goal - n <= 1000 && !visited[goal - n]) {
                        nq.push(goal - n);
                        visited[goal - n] = true;
                    }
                    if ((goal ^ n) >= 0 && (goal ^ n) <= 1000 && !visited[(goal ^ n)]) {
                        nq.push((goal ^ n));
                        visited[(goal ^ n)] = true;
                    }
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<bool> visited(1001, false);
        queue<int> nq;
        nq.push(start);      
        int count = -1;        
        while (!nq.empty()) {
            count++;
            int size = nq.size();
            for (int i = 0; i < size; i++) {
                int curr = nq.front();
                nq.pop();
                if (curr == goal) {
                    return count;
                }
                if (curr < 0 || curr > 1000 || visited[curr]) {
                    continue;
                }
                visited[curr] = true;
                for (int n : nums) {
                    nq.push(curr + n);
                    nq.push(curr - n);
                    nq.push(curr ^ n);
                }
            }            
        }
        return -1;
    }
};
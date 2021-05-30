class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        auto comparator = [](pair<int, int>& left, pair<int, int>& right) {
            return (left.first == right.first) ? left.second > right.second : left.first > right.first;            
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> free(comparator), busy(comparator);
        for (int i = 0; i < servers.size(); i++) {
            free.push({servers[i], i});
        }
        vector<int> res;
        int sec = 0, ind = 0, m = tasks.size();
        while (ind < m) {
            while (!busy.empty() && busy.top().first <= sec) {
                int done = busy.top().second;
                busy.pop();
                free.push({servers[done], done});
            }
            while (!free.empty() && sec >= ind && ind < m) {
                int pick = free.top().second;
                free.pop();                
                busy.push({sec + tasks[ind], pick});
                res.push_back(pick);
                ind++;
            }
            if (free.empty()) {
                sec = busy.top().first;
            } else {
                sec = ind;
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res;        
        auto comparator = [](pair<int, int> left, pair<int, int> right) {
            if (left.second == right.second) return left.first > right.first;
            return left.second > right.second;
        };                        
                
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> start(comparator), curr(comparator);
        for (int i = 0; i < tasks.size(); i++) {            
            start.push({i, tasks[i][0]});
        }        
        long time = 0;        
        while (!start.empty() || !curr.empty()) {            
            while (!start.empty() && (start.top().second <= time || curr.empty())) {                
                if (curr.empty() && time < start.top().second) time = start.top().second;
                curr.push({start.top().first, tasks[start.top().first][1]});
                start.pop();
            }                        
            
            if (!curr.empty()) {                
                time += curr.top().second;
                res.push_back(curr.top().first);
                curr.pop();                        
            }                      
        }
        return res;
    }
};
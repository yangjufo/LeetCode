class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k <= 0) return s;
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        auto comparator = [](pair<int, int> left, pair<int, int> right) {
            return left.second < right.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(comparator);
        
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                pq.push({i, count[i]});
            }
        }
        
        string res;
        queue<pair<int, int>> waitQueue;
        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();
            res += curr.first + 'a';
            curr.second -= 1;
            waitQueue.push(curr);
            
            if (waitQueue.size() < k) {
                continue;
            }
            
            pair<int, int> next = waitQueue.front();
            waitQueue.pop();
            if (next.second > 0) {
                pq.push(next);
            }
        }
        
        return res.length() == s.length() ? res : "";
        
    }
};
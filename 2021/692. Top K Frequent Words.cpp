class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordCounter;
        for (string w : words) {
            wordCounter[w]++;
        }
        
        auto comparator = [](pair<string, int>& left, pair<string, int>& right) {
            if (left.second == right.second) return left.first < right.first;
            return left.second > right.second;
        };
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comparator)> pq(comparator);
        
        for (auto& iter : wordCounter) {
            pq.push({iter.first, iter.second});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
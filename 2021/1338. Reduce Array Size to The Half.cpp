class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int a : arr) {
            count[a]++;
        }        
        auto comparator = [](pair<int, int> left, pair<int, int> right) {
            return left.second < right.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(comparator);
        for (auto& iter : count) {
            pq.push({iter.first, iter.second});
        }
        int removedNum = 0, removedCount = 0;
        while (removedCount * 2 < arr.size() && !pq.empty()) {
            removedCount += pq.top().second;
            removedNum++;
            pq.pop();
        }
        return removedNum;
    }
};
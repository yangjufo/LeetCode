class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comparator = [](vector<int>& left, vector<int>& right) {
            return left[0] * left[0] + left[1] * left[1] < right[0] * right[0] + right[1] * right[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> pq(comparator);
        for (vector<int>& p : points) {
            pq.push(p);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
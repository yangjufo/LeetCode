class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> pq;
        int maxVal = INT_MIN;
        for (vector<int>& p : points) {            
            while (!pq.empty() && p[0] - pq.front().first > k) {
                pq.pop_front();
            }
            if (!pq.empty()) {
                maxVal = max(maxVal, pq.front().second + p[1] + (p[0] - pq.front().first));
            }
            while (!pq.empty() && p[1] - p[0] >= pq.back().second - pq.back().first) {
                pq.pop_back();
            }        
            pq.push_back({p[0], p[1]});
        }
        return maxVal;
    }
};
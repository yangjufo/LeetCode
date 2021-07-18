class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> curr, prev;
        for (int p : points[0]) {
            prev.push_back(p);
        }
        curr = prev;
        for (int i = 1; i < m; i++) {
            long long prevMax = INT_MIN;
            for (int j = 0; j < n; j++) {                
                prevMax = max(prevMax, prev[j] + j);
                curr[j] = prevMax + points[i][j] - j;
            }
            prevMax = INT_MIN;
            for (int j = n - 1; j > -1; j--) {
                prevMax = max(prevMax, prev[j] - j);
                curr[j] = max(curr[j], prevMax + points[i][j] + j);
            }
            swap(curr, prev);
        }
        
        return *max_element(prev.begin(), prev.end());
    }
};
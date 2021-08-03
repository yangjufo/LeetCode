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

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<long long> curr;
        for (int p : points[0]) {
            curr.push_back(p);
        }
        for (int i = 1; i < points.size(); i++) {
            vector<long long> prev = curr;
            long long preMax = INT_MIN;
            for (int j = 0; j < points[0].size(); j++) {
                preMax = max(preMax, prev[j] + j);
                curr[j] = preMax - j + points[i][j];
            }
            long long postMax = INT_MIN;
            for (int j = (int)points[0].size() - 1; j >= 0; j--) {
                postMax = max(postMax, prev[j] - j);
                curr[j] = max(curr[j], postMax + j + points[i][j]);
            }            
            prev = curr;            
        }
        long long res = 0;
        for (int j = 0; j < points[0].size(); j++) {
            res = max(res, curr[j]);
        }
        return res;
    }
};
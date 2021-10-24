class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<int> degrees(n, 0), left(n, 0), right(n, 0);
        for (int i = 1; i < parents.size(); i++) {
            degrees[parents[i]]++;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            if (degrees[i] == 0) {
                pq.push(i);
                degrees[i] = -1;
            }
        }
        long long maxVal = 0, maxCount = 0;
        while (!pq.empty()) {
            int node = pq.top();
            pq.pop();
            long long prod = 1;
            if (left[node] != 0) {
                prod *= left[node];
            }
            if (right[node] != 0) {
                prod *= right[node];
            }
            if (node != 0) {
                prod *= n - left[node] - right[node] - 1;
                if (left[parents[node]] == 0) {
                    left[parents[node]] = left[node] + right[node] + 1;
                } else {                    
                    right[parents[node]] = left[node] + right[node] + 1;
                }
                degrees[parents[node]] --;
                if (degrees[parents[node]] == 0) {
                    pq.push(parents[node]);
                    degrees[parents[node]] = -1;
                }
            }
            if (prod > maxVal) {
                maxVal = prod;
                maxCount = 1;
            } else if (prod == maxVal) {
                maxCount += 1;
            }            
        }
        return maxCount;
    }
};
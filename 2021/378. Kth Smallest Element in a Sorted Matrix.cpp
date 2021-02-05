
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto Comparator = [](vector<int>& left, vector<int>& right) {
            return left[2] > right[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(Comparator)> pq(Comparator);
        for (int i = 0; i < matrix[0].size(); i++) {
            pq.push({0, i, matrix[0][i]});
        }        
        
        for (int i = 0; i < k - 1; i++) {
            auto top = pq.top();
            pq.pop();
            if (top[0] < matrix.size() - 1) {
                pq.push({top[0] + 1, top[1], matrix[top[0] + 1][top[1]]});
            }
        }
        return pq.top()[2];
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int lo = matrix[0][0], hi = matrix[matrix.size() - 1][matrix[0].size() - 1];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int count = 0;
            int j = matrix[0].size() - 1;
            for (int i = 0; i < matrix.size(); i++) {                
                while (j >= 0 && matrix[i][j] > mid) j--;
                count += (j + 1);
            }
            if (count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};

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

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = matrix[0][0], hi = matrix[m - 1][n - 1];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2, count = 0, j = n - 1;           
            for (int i = 0; i < m; i++) {
                while (j >= 0 && matrix[i][j] > mid) {
                    j--;
                }
                count += j + 1;
            }
            if (count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto comparator = [](array<int, 3>& left, array<int, 3>& right) {
            return left[2] > right[2];
        };
        
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comparator)> pq(comparator);
        for (int i = 0; i < matrix[0].size(); i++) {
            pq.push({0, i, matrix[0][i]});
        }
        
        for (int i = 0; i < k - 1; i++) {            
            int row = pq.top()[0], col = pq.top()[1];
            pq.pop();
            if (row + 1 < matrix.size()) {
                pq.push({row + 1, col, matrix[row + 1][col]});
            }
        }
        return pq.top()[2];
    }
};


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto comparator = [](array<int, 3>& left, array<int, 3>& right) {
            return left[2] > right[2];
        };
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comparator)> pq(comparator);
        for (int i = 0; i < matrix[0].size() && i < k; i++) {
            pq.push({0, i, matrix[0][i]});
        }
        
        for (int i = 0; i < k - 1; i++) {
            auto curr = pq.top();
            pq.pop();
            if (curr[0] + 1 < matrix.size()) {
                pq.push({curr[0] + 1, curr[1], matrix[curr[0] + 1][curr[1]]});
            }            
        }
        
        return pq.top()[2];
    }
};


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + (right - left) / 2, count = 0, j = n - 1;
            for (int i = 0; i < n; i++) {
                while (j >= 0 && matrix[i][j] > mid) {
                    j--;
                }
                count += j + 1;
            }
            if (count < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
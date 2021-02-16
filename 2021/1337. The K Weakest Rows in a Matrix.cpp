class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        auto comparator = [](pair<int, int> left, pair<int, int> right) {
            if (left.second == right.second) {
                return left.first < right.first;
            }
            return left.second < right.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(comparator);
        for (int i = 0; i < mat.size(); i++) {
            pq.push({i, getLastSoldierIndex(mat[i])});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
    
    int getLastSoldierIndex(vector<int>& row) {
        int left = 0, right = row.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (row[mid] == 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return row[left] == 0 ? left - 1 : left;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        for (int j = 0; j < mat[0].size() && res.size() < k; j++) {
            for (int i = 0; i < mat.size() && res.size() < k; i++) {
                if (mat[i][j] == 0 && (j == 0 || mat[i][j - 1] != 0)) {
                    res.push_back(i);
                }
            }
        }
        for (int i = 0; i < mat.size() && res.size() < k; i++) {
            if (mat[i][mat[0].size() - 1] == 1) {
                res.push_back(i);
            }
        }
        return res;
    }
};
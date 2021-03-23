class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {        
        for (int i = 0; i < mat[0].size(); i++) {            
            int j = 1;
            while (j < mat.size() && binary_search(mat[j].begin(), mat[j].end(), mat[0][i])) {
                j++;
            }
            if (j == mat.size()) return mat[0][i];
        }
        return -1;
    }
};

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int count[10001] = {}, m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; j++) {
                count[mat[i][j]]++;
            }
        }
        for (int k = 1; k <= 10000; k++) {
            if (count[k] == m) {
                return k;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int currMax = 0, count = 0;
        vector<int> pos(m);
        while (true) {
            for (int i = 0; i < m; i++) {
                while (pos[i] < m && mat[i][pos[i]] < currMax) {
                    pos[i]++;
                }
                if (pos[i] >= n) {
                    return -1;
                }
                if (currMax != mat[i][pos[i]]) {
                    count = 1;
                    currMax = mat[i][pos[i]];
                } else {                    
                    count++;
                    if (count == m) {
                        return currMax;
                    }                    
                }
            }
        }        
        return -1;
    }
};
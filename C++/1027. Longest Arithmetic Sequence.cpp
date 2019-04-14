class Solution {
public:
    int maxLen;
    
    int longestArithSeqLength(vector<int>& A) {
        maxLen = 2;
        vector<unordered_map<int, vector<int>>> subMap(A.size(), unordered_map<int, vector<int>>{});
        for (int i = 1; i < A.size(); i++) {
            for (int j = 0; j < i; j++) {
                subMap[j][A[i] - A[j]].push_back(i);
            }
        }
        for (int i = 0; i < A.size(); i++){ 
            for (auto iter = subMap[i].begin(); iter != subMap[i].end(); iter++) {
                for (int j : iter->second)
                    dfs(subMap, 2, j, iter->first);
            }
        }
        return maxLen;
    }
    void dfs(vector<unordered_map<int, vector<int>>>& subMap, int len, int ind, int diff) {        
        maxLen = max(len, maxLen);
        if (subMap[ind].find(diff) != subMap[ind].end()){      
            for (int i : subMap[ind][diff]) {
                if (i > ind)
                    dfs(subMap, len + 1, i, diff);
            }
        }        
    }
};
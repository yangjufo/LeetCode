class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        // sort(source.begin(), source.end());
        // for (int i : source) {
        //     cout << i << " ";
        // }
        // cout << endl;
        // sort(target.begin(), target.end());
        // for (int i : target) {
        //     cout << i << " ";
        // }
        // cout << endl;
        
        vector<int> parents(source.size(), 0);
        for (int i = 0; i < source.size(); i++) {
            parents[i] = i;
        }
        
        for (vector<int>& swap : allowedSwaps) {
            merge(parents, swap[0], swap[1]);
        }
        
        unordered_map<int, unordered_map<int, int>> leftCount, rightCount;
        
        for (int i = 0; i < source.size(); i++) {
            int p = find(parents, i);
            leftCount[p][source[i]]++;
            rightCount[p][target[i]]++;
        }
        
        int ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (leftCount.find(i) != leftCount.end()) {
                int same = 0, total = 0;
                for (auto iter : leftCount[i]) {       
                    same += min (iter.second, rightCount[i][iter.first]);                    
                    total += iter.second;
                }
                ans += total - same;
            }
        }
        return ans;        
    }
    
    void merge(vector<int>& parents, int left, int right) {
        int pL = find(parents, left);
        int pR = find(parents, right);
        parents[pL] = pR;
    }
    
    int find(vector<int>& parents, int node) {
        if (parents[node] == node) return node;
        return find(parents, parents[node]);
    }
    
};
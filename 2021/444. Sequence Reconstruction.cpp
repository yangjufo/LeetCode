class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<vector<int>> edges(n + 1);
        vector<int> degrees(n + 1, 0);
        vector<bool> visited(n + 1, false);
        for (vector<int>& seq : seqs) {
            for (int i = 0; i < seq.size(); i++) {
                if (seq[i] < 1 || seq[i] > n) return false;
                visited[seq[i]] = true;
                if (i >= 1) {
                    edges[seq[i - 1]].push_back(seq[i]);
                    degrees[seq[i]]++;
                }                                
            }                               
        }
        int curr = -1, count = 0;        
        for (int i = 1; i <= n; i++) {            
            if (!visited[i]) return false;
            if (degrees[i] == 0) {
                if (curr != -1) {
                    return false;
                }
                curr = i;
                degrees[i]--;
            }             
        }                
        while (curr != -1 && count < n && curr == org[count]) {
            count++;
            int next = -1;
            for (int neigh : edges[curr]) {
                degrees[neigh]--;
                if (degrees[neigh] == 0) {
                    if (next != -1) {
                        return false;
                    }
                    next = neigh;
                    degrees[neigh]--;
                }
            }
            curr = next;
        }
        
        return count == n;
    }
};
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> edges;
        unordered_set<int> nodes;
        for (vector<int>& piece : pieces) {
            for (int i = 0; i < piece.size() - 1; i++) {
                edges[piece[i]] = piece[i + 1];
                nodes.insert(piece[i]);
            }            
            nodes.insert(piece.back());
        }
        
        for (int i = 0; i < arr.size() - 1; i++) {
            if (!nodes.count(arr[i]) || (edges.count(arr[i]) && edges[arr[i]] != arr[i + 1])) return false; 
        }
        
        return nodes.count(arr.back()) && !edges.count(arr.back());                
    }
};

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<int> ps(101, -1);
        for (int i = 0; i < pieces.size(); i++) {
            ps[pieces[i][0]] = i;
        }
        int i = 0;
        while (i < arr.size()) {
            int pInd = ps[arr[i]];
            if (pInd == -1) return false;
            for (int j = 0; j < pieces[pInd].size(); j++) {
                if (pieces[pInd][j] != arr[i]) return false;
                i++;
            }
        }
        return true;
    }
};
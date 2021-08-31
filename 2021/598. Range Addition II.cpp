class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int w = m, h = n;
        for (vector<int>& op : ops) {
            w = min(w, op[0]);
            h = min(h, op[1]);        
        }
        return w * h;
    }
};

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int w = m, h = n;
        for (vector<int>& op : ops) {
            w = min(w, op[0]);
            h = min(h, op[1]);
        }
        return w * h;
    }
};
class ZigzagIterator {
public:
    vector<vector<int>> vs;
    int index[2], curr;    
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        vs.push_back(v1);
        vs.push_back(v2);
        index[0] = index[1] = 0;
        curr = 0;        
    }

    int next() { 
        if (!hasNext()) {
            return -1;
        }
        int ret = vs[curr][index[curr]];
        index[curr] += 1;
        curr = 1 - curr;
        return ret;
    }

    bool hasNext() {        
        if (index[0] >= vs[0].size() && index[1] >= vs[1].size()) return false;
        if (index[curr] >= vs[curr].size()) {
            curr = 1 - curr;
        }
        return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
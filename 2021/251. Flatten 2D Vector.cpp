class Vector2D {
public:    
    int outIndex = 0, inIndex = 0;
    vector<vector<int>> v;
    Vector2D(vector<vector<int>>& v) {
        this->v = v;
    }
    
    int next() {
        if (!hasNext()) return -1;
        inIndex++;
        return v[outIndex][inIndex - 1];
    }
    
    bool hasNext() {
        while (outIndex < v.size() && inIndex >= v[outIndex].size()) {
            outIndex++;
            inIndex = 0;
        }
        return outIndex < v.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
class RangeFreqQuery {
public:
    vector<vector<int>> freq;
    RangeFreqQuery(vector<int>& arr) {
        freq.resize(10001);
        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto iterLeft = lower_bound(freq[value].begin(), freq[value].end(), left);
        auto iterRight = upper_bound(freq[value].begin(), freq[value].end(), right);
        return iterRight - iterLeft;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res = {label};
        while (label != 1) {
            int parent = label / 2;
            int first = (int) log2(parent);
            int start =  (int)pow(2, first), end = (int) pow(2, first + 1) - 1 ;
            label = end - parent + start;
            res.push_back(label);            
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
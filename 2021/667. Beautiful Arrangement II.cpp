class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for (int i = 1, j = n; i <= j;) {
            if (k > 1) {
                if (k % 2 == 0) {
                    res.push_back(j);
                    j--;
                } else {
                    res.push_back(i);
                    i++;
                }
                k--;
            } else {
                res.push_back(i);
                i++;
            }            
        }
        return res;
    }
};
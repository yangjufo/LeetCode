class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> seq, res;
        for (int n : obstacles) {
            auto iter = upper_bound(seq.begin(), seq.end(), n);            
            res.push_back(iter - seq.begin() + 1);
            if (iter == seq.end()) {
                seq.push_back(n);                
            } else {                
                *iter = n;
            }                        
        }
        return res;
    }
};
class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int curr = 0, count = 0;
        for (int r : rungs) {
            if (r - curr > dist) {
                count += (r - curr - 1) / dist;                
            }
            curr = r;                        
        }
        return count;
    }
};
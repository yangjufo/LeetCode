class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> reach;                
        for (int i = 0; i < dist.size(); i++) {
            reach.push_back((dist[i] + speed[i] - 1) / speed[i]);
        }
        sort(reach.begin(), reach.end());        
        int count = 0;
        while (count < reach.size()) {
            if (reach[count] <= count) {
                break;
            }            
            count++;
        }
        return count;
    }
};
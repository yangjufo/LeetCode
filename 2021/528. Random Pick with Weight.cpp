class Solution {
public:
    vector<int> preSum;
    
    Solution(vector<int>& w) {     
        int sum = 0;
        for (int weight : w) {
            sum += weight;
            preSum.push_back(sum);
        }                
    }
    
    int pickIndex() {
        float num = (float) rand() / RAND_MAX * preSum.back();
        int left = 0, right = preSum.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (preSum[mid] < num) {
                left = mid + 1;
            } else {
                right = mid;
            }            
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
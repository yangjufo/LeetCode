class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> evens;
        int minVal = INT_MAX;
        for (int n : nums) {
            if ((n & 0x1) == 0) {
                evens.push(n);
                minVal = min(minVal, n);
            } else {
                evens.push(n << 1);
                minVal = min(minVal, n << 1);
            }
        }
        
        int ans = INT_MAX;
        while (!evens.empty()) {
            int currVal = evens.top();
            evens.pop();
            ans = min(ans, currVal - minVal);
            if ((currVal & 0x1) == 0) {
                evens.push(currVal >> 1);
                minVal = min(currVal >> 1, minVal);
            } else {
                break;
            }
        }
        return ans;
    }
};
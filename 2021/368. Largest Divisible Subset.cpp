class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int N = nums.size(), maxCount = 0, maxIndex = 0;        
        vector<int> count(N, 1), prev(N, -1);        
        for (int i = 0; i < N; i++) {                    
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && count[j] + 1 > count[i]) {                    
                    count[i] = count[j] + 1;
                    prev[i] = j;                    
                }                                
            }            
            if (count[i] > maxCount) {
                maxCount = count[i];
                maxIndex = i;
            }
        }
        
        vector<int> res;
        while (maxIndex > -1) {
            res.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> count(nums.size(), 1), prev(nums.size(), - 1);
        int maxCount = 0, maxIndex = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {                
                if (nums[i] % nums[j] == 0 && count[j] + 1 > count[i]) {
                    count[i] = count[j] + 1;
                    prev[i] = j;
                }
            }
            if (count[i] > maxCount) {
                maxCount = count[i];
                maxIndex = i;
            }
        }
        vector<int> res;
        while (maxIndex > -1) {            
            res.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }
        return res;
    }
};
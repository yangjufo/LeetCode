class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long, int> count;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                count[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for (auto iter : count) {
            if (iter.second >= 2) {
                int n = iter.second;                
                ans += n * (n - 1) * 4;
            }
        }
        return ans;
    }    
};

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long, int> count;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int prod = nums[i] * nums[j];
                ans += 8 * count[prod];
                count[prod]++;
            }
        }        
        return ans;
    }    
};
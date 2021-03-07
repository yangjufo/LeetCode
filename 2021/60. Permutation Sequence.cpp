class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factor(n, 0), nums;
        factor[0] = 1;
        nums.push_back(1);
        for (int i = 1; i < n; i++) {
            factor[i] = factor[i - 1] * i;
            nums.push_back(i + 1);
        }
        
        k--;
        string res;
        for (int i = n - 1; i >= 0; i--) {            
            int index = k / factor[i];
            k -= index * factor[i];                           
            
            res += to_string(nums[index]);            
            nums.erase(nums.begin() + index);
        }
        return res;        
    }       
};
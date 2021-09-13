class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxNumProduct = nums[0];
        int maxCurrentProduct = nums[0];
        int minCurrentProduct = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                int tmp = maxCurrentProduct;
                maxCurrentProduct = minCurrentProduct;
                minCurrentProduct = tmp;
            }
            maxCurrentProduct = max(maxCurrentProduct * nums[i], nums[i]);
            minCurrentProduct = min(minCurrentProduct * nums[i], nums[i]);
            maxNumProduct = max(maxNumProduct, maxCurrentProduct);
        }        
        return maxNumProduct;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = nums[0], minP = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(maxP, minP);
            }            
            maxP = max(nums[i], maxP * nums[i]);
            minP = min(nums[i], minP * nums[i]);
            res = max(maxP, res);
        }
        return res;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = 1, minP = 1, res = nums[0];
        for (int n : nums) {
            if (n < 0) {
                swap(maxP, minP);
            }
            maxP = max(n, maxP * n);
            minP = min(n, minP * n);
            res = max(maxP, res);
            if (maxP == 0) {
                maxP = 1;
            }
            if (minP == 0) {
                minP = 1;
            }
        }
        return res;
    }    
};
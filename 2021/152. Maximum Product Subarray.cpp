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
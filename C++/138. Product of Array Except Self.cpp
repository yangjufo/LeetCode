class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> preProduct;                
        vector<int> sufProduct;
        vector<int> result;
        int count = 0;
        preProduct.push_back(nums.front());
        sufProduct.push_back(nums.back());
        for(vector<int>::iterator iter = nums.begin() + 1; iter != nums.end(); iter++){
            preProduct.push_back(preProduct.back() * *iter);
        }
        for(vector<int>::iterator iter = nums.end() - 2; (iter+1) != nums.begin(); iter--){
            sufProduct.push_back(sufProduct.back() * *iter);
        }        
        int n = nums.size();
        while(result.size()  < n){
            if (result.empty())
                result.push_back(sufProduct[n - 2]);
            else if (result.size() + 1 == n)
                result.push_back(preProduct[n - 2]);
            else
                result.push_back(preProduct[result.size() - 1] * sufProduct[n - result.size() - 2]);     
        }
        return result;
    }
};
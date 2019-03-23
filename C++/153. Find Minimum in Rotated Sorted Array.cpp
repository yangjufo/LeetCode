class Solution {
public:
    int findMin(vector<int>& nums) {
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end()  - 1; iter++){
            if (*iter > *(iter + 1))
                return *(iter + 1);
        }
        return nums.front();
    }
};
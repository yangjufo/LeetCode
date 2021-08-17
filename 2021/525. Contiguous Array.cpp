class Solution {
public:
    int findMaxLength(vector<int>& nums) {        
        unordered_map<int, int> diffMap = {{0, -1}};
        int zeroCount = 0, oneCount = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroCount++;
            } else {
                oneCount++;
            }        
            if (diffMap.find(zeroCount - oneCount) != diffMap.end()) {
                maxLen = max(i - diffMap[zeroCount - oneCount], maxLen);
            } else {
                diffMap[zeroCount - oneCount] = i;
            }
        }
        return maxLen;
    }
};
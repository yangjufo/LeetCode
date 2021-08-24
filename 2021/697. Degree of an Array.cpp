class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {        
        unordered_map<int, int> starts, ends, count;
        int maxFreq = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (starts.find(nums[i]) == starts.end()) {
                starts[nums[i]] = i;
            }            
            ends[nums[i]] = i;        
            count[nums[i]]++;
            maxFreq = max(maxFreq, count[nums[i]]);
        }        
        int minLen = nums.size();
        for (auto& iter : count) {
            if (iter.second == maxFreq) {
                minLen = min(minLen, ends[iter.first] - starts[iter.first] + 1);
            }
        }
        return minLen;
    }
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {        
        unordered_map<int, int> starts, count;
        int maxFreq = 0, minLen = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (starts.find(nums[i]) == starts.end()) {
                starts[nums[i]] = i;
            }                        
            count[nums[i]]++;                        
            if (count[nums[i]] > maxFreq) {                                
                maxFreq = count[nums[i]];
                minLen = i - starts[nums[i]] + 1;
            } else if (count[nums[i]] == maxFreq) {
                minLen = min(minLen, i - starts[nums[i]] + 1);
            }
        }                
        return minLen;
    }
};
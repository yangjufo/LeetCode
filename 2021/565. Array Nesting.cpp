class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<int> mem(nums.size(), 0);
        int count = 0, index = 0;
        while (count < nums.size()) {
            if (mem[nums[index]] == 0) {                
                vector<int> loop;
                unordered_set<int> curr;
                int start = index;
                while (mem[nums[start]] == 0 && curr.find(nums[start]) == curr.end()) {
                    count++;
                    loop.push_back(nums[start]);
                    curr.insert(nums[start]);
                    start = nums[start];                    
                }
                int append = mem[nums[start]];
                for (int i = 0; i < loop.size(); i++) {
                    mem[loop[i]] = (int)loop.size() - i + append;
                }
            }            
            index++;
        }
        int maxLen = 0;
        for (int n : mem) {
            maxLen = max(maxLen, n);
        }
        return maxLen;
    }
};

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                int start = nums[i], count = 0;
                do {
                    start = nums[start];
                    count++;
                    visited[start] = true;
                } while (start != nums[i]);
                maxLen = max(maxLen, count);
            }            
        }
        return maxLen;
    }
};
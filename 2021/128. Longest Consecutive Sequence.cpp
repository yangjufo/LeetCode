class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> countMap;
        int ans = 0;
        for (int n : nums) {
            if (!countMap.count(n)) {
                int left = countMap.count(n - 1) ? countMap[n - 1] : 0;
                int right = countMap.count(n + 1) ? countMap[n + 1] : 0;
                
                int sum = left + right + 1;
                ans = max(sum, ans);
                
                countMap[n] = sum;
                countMap[n - left] = sum;
                countMap[n + right] = sum;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> countMap;
        int ans = 0;
        for (int n : nums) {
            if (!countMap.count(n)) {
                int left = countMap.count(n - 1) ? countMap[n - 1] : 0;
                int right = countMap.count(n + 1) ? countMap[n + 1] : 0;
                
                int sum = left + right + 1;
                ans = max(sum, ans);
                
                countMap[n] = sum;
                countMap[n - left] = sum;
                countMap[n + right] = sum;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> countMap;
        int maxLen = 0;
        for (int n : nums) {
            if (countMap.find(n) != countMap.end()) continue;
            int left = countMap.find(n - 1) == countMap.end() ? 0 : countMap[n - 1];
            int right = countMap.find(n + 1) == countMap.end() ? 0 : countMap[n + 1];
            int sum = left + right + 1;            
            countMap[n] = sum;
            countMap[n - left] = sum;
            countMap[n + right] = sum;
            maxLen = max(maxLen, sum);
        }
        cout << maxLen << endl;
        return maxLen;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();        
        if (m > 6 * n || n > 6 * m) return -1;
        
        unordered_map<int, int> coins1, coins2;        
        
        int sum1 = 0, sum2 = 0;
        for (int n : nums1) {
            sum1 += n;
            coins1[1 - n]++;
            coins1[6 - n]++;
        }
        for (int n : nums2) {
            sum2 += n;
            coins2[1 - n]++;
            coins2[6 - n]++;
        }
        
        
        int minCount = m + n;
        if (sum1 > sum2) {
            int diff = sum1 - sum2, currCount = 0;
            for (int i = 5; i >= 1; i--) {                
                if (i * (coins1[-i] + coins2[i]) >= diff) {
                    currCount += (diff + i - 1) / i;
                    break;
                } else {
                    diff -= i * (coins1[-i] + coins2[i]);
                    currCount += (coins1[-i] + coins2[i]);
                }
            }
            minCount = min(minCount, currCount);
        } else {
            int diff = sum2 - sum1, currCount = 0;
            for (int i = 5; i >= 1; i--) {                
                if (i * (coins2[-i] + coins1[i]) >= diff) {
                    currCount += (diff + i - 1) / i;
                    break;
                } else {
                    diff -= i * (coins2[-i] + coins1[i]);
                    currCount += (coins2[-i] + coins1[i]);
                }
            }
            minCount = min(minCount, currCount);
        }
        return minCount;
    }        
};

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();        
        if (m > 6 * n || n > 6 * m) return -1;
        
        unordered_map<int, int> coins1, coins2;        
        
        int sum1 = 0, sum2 = 0;
        for (int n : nums1) {
            sum1 += n;           
        }
        for (int n : nums2) {
            sum2 += n;            
        }
        
        if (sum1 < sum2) {
            return minOperations(nums2, nums1);
        }        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = m - 1, j = 0, diff = sum1 - sum2, count = 0;
        while (diff > 0) {
            if (i < 0 || (j < n && nums1[i] - 1 < 6 - nums2[j])) {
                diff -= 6 - nums2[j];
                j++;
            } else {
                diff -= nums1[i] - 1; 
                i--;
            }
            count++;
        }
        
        return count;
    }        
};
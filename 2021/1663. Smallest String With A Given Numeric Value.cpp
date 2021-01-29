class Solution {
public:    
    string getSmallestString(int n, int k) {
        string ans;
        int curr = 0;
        for (int i = n; i >= 1; i--) {
            int left = 1, right = 26;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (k - mid - curr > i - 1) {
                    left = mid + 1;
                } else {
                    right = mid;
                }                
            }
            curr += left;
            ans += left - 1 + 'a';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }        
};


class Solution {
public:    
    string getSmallestString(int n, int k) {
        string ans;
        for (int i = n; i >= 1; i--) {
            if (k - (i - 1) >= 26) {
                ans += 'z';
                k -= 26;
            } else {
                ans += (k - (i - 1) - 1) + 'a';
                k = i - 1;
            }            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }        
};
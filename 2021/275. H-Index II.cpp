class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 1 && citations[0] == 0) return 0;
        int n = citations.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (n - mid > citations[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }                        
        }                
        return (n - left > citations[left]) ? n - left - 1 : n - left;
    }
};
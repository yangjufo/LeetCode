class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {        
        unordered_map<int, int> removeMap;
        for (int i = 0; i < removable.size(); i++) {
            removeMap[removable[i]] = i;
        }
        int left = 0, right = (int) removable.size();        
        while (left < right) {
            int mid = left + (right - left) / 2;            
            if (isSub(s, p, mid, removeMap)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    bool isSub(string& s, string& p, int k, unordered_map<int, int>& removeMap) {
        int i = 0, j = 0;
        while (i < s.length() && j < p.length()) {
            if ((removeMap.find(i) == removeMap.end() || removeMap[i] > k) && s[i] == p[j]) {
                j++;
            }
            i++;
        }
        return j >= p.length();
    }
};
class Solution {
public:
    vector<pair<char, char>> pairs = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    int count = 0;
    int strobogrammaticInRange(string low, string high) {
        string curr(low.length() - 1, '0');        
        for (int len = low.length(); len <= high.length(); len++) {
            curr += "0";            
            dfs(low, high, curr, 0, len - 1);            
        }
        return count;
    }
    
    void dfs(string& low, string& high, string& curr, int left, int right) {
        if (left > right) {
            if ((curr.length() == low.length() && curr < low)
                || (curr.length() == high.length() && curr > high)) {
                return;
            }
            count++;
            return;
        }
        for (pair<char, char>& p : pairs) {
            curr[left] = p.first;
            curr[right] = p.second;
            if (curr.length() != 1 && curr[0] == '0') continue;
            if (left == right && p.first != p.second) continue;
            dfs(low, high, curr, left + 1, right - 1);
        }
    }
};
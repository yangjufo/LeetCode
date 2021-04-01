class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        vector<bool> visited(target.length(), false);
        int count = 0;
        while (count < target.length()) {
            bool replaced = false;
            for (int i = 0; i <= target.length() - stamp.length() && count < target.length(); i++) {
                if (!visited[i] && canReplace(stamp, i, target)) {                    
                    visited[i] = true;
                    replaced = true;
                    count = doReplace(stamp, i, target, count);
                    res.push_back(i);                    
                }
            }
            if (!replaced) {
                return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool canReplace(string& stamp, int offset, string& target) {
        for (int i = 0; i < stamp.length(); i++) {            
            if (target[i + offset] != '*' && target[i + offset] != stamp[i]) {
                return false;
            }
        }
        return true;
    }
    
    int doReplace(string& stamp, int offset, string& target, int count) {
        for (int i = 0; i < stamp.length(); i++) {
            if (target[i + offset] != '*') {
                target[i + offset] = '*';
                count++;
            }
        }
        return count;
    }
};
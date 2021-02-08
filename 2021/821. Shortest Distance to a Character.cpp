class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> cPos;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                cPos.push_back(i);
            }
        }
        vector<int> res;
        for (int i = 0; i < s.length(); i++) {
            int left = 0, right = cPos.size() - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (cPos[mid] > i) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            res.push_back(abs(cPos[left] - i));
            if (left > 0 && abs(cPos[left - 1] - i) < res.back()) {
                res[res.size() - 1] = abs(cPos[left - 1] - i);
            }                        
        }
        return res;
    }
};

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res;
        int prev = -s.length();
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) prev = i;
            res.push_back(i - prev);
        }
                
        prev = s.length() * 2;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == c) prev = i;
            res[i] = min(res[i], prev - i);
        }
        
        return res;
    }
};
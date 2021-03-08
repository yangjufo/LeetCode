class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        string curr;
        backtrack(s, curr, 0, 0);
        return res;
    }
    
    void backtrack(string& s, string curr, int start, int count) {
        if (start >= s.length() && count == 4) {
            res.push_back(curr.substr(0, curr.length() - 1));
        }
        if (count >= 4) return;        
        int num = 0, i = start;
        while (i < s.length()) {
            if (i != start && num == 0) break;
            num = num * 10 + (s[i] - '0');
            if (num > 255) break;            
            backtrack(s, curr + to_string(num) + ".", i + 1, count + 1);
            i++;
        }
    }
};

class Solution {
public: 
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        vector<string> segments;
        backtrack(s, 0, segments);
        return res;                
    }       
    
    void backtrack(string& s, int start, vector<string>& segments) {
        if (start >= s.length() && segments.size() == 4) {
            string curr;
            for (int i = 0; i < 3; i++) {
                curr += segments[i] + ".";
            }            
            res.push_back(curr + segments.back());
        }        
        if (segments.size() >= 4) return;
        int num = 0;
        string tmp;
        for (int i = 0; i <= 2 && start + i < s.length(); i++) {
            if (i != 0 && num == 0) break;
            num = num *10 + s[start + i] - '0';
            tmp += s[start + i];
            if (num > 255) break;
            segments.push_back(tmp);
            backtrack(s, start + i + 1, segments);
            segments.pop_back();
        }
    }
};
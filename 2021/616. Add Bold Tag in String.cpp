class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        vector<pair<int, int>> intervals;
        for (int i = 0; i < s.length(); i++) {
            for (string& w : words) {
                if (s.substr(i, w.length()) == w) {
                    if (intervals.empty() || i > intervals.back().second) {
                        intervals.push_back({i, i + w.length()});
                    } else {
                        intervals.back().second = max((int)intervals.back().second, (int)(i + w.length()));
                    }                    
                }
            }
        }        
        string res;
        int j = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (j < intervals.size()) {
                if (i == intervals[j].first) {
                    res += "<b>";
                } else if (i == intervals[j].second) {
                    res += "</b>";
                    j++;
                }
            }
            if (i < s.length()) {
                res += s[i];
            }            
        }
        return res;
    }
};

class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        vector<bool> bold(s.length(), false);
        for (int i = 0, end = 0; i < s.length(); i++) {
            for (string& w : words) {
                if (s.find(w, i) == i) {
                    end = max(end, i + (int)w.length());
                }
            }
            bold[i] = end > i;   
        }
        
        string res;
        int i = 0;
        while (i < s.length()) {
            if (!bold[i]) {
                res += s[i];
                i++;
                continue;
            }
            int start = i;
            while (i < s.length() && bold[i]) i++;
            res += "<b>" + s.substr(start, i - start) + "</b>";
        }
        return res;
    }
};
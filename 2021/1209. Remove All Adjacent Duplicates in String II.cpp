class Solution {
public:
    string removeDuplicates(string s, int k) {
        char c = s[0];
        int count = 1;
        stack<pair<char, int>> counts;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != c) {
                if (count % k == 0) {                    
                    if (!counts.empty() && counts.top().first == s[i]) {                        
                        count = counts.top().second + 1;
                        counts.pop();
                    } else {
                        count =1;
                    }
                } else {                    
                    counts.push({c, count % k});
                    count = 1;
                }                
                c = s[i];
            } else {
                count++;
            }
        }
        string res;
        if (count % k != 0) {
            res += string(count % k, c);            
        }
        while (!counts.empty()) {
            res += string(counts.top().second, counts.top().first);
            counts.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> counts = {{'#', 0}};
        for (char c : s) {
            if (counts.back().first != c) {                
                counts.push_back({c, 1});
            } else {                
                counts.back().second++;
                if (counts.back().second == k) {
                    counts.pop_back();
                }
            }
        }
        string res;
        for (auto& p : counts) {
            res += string(p.second, p.first);
        }
        return res;
    }
};

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int i = 0, n = s.length();
        vector<int> counts(n, 0);
        for (int j = 0; j < s.length(); i++, j++) {
            s[i] = s[j];
            counts[i] = (i > 0 && s[i - 1] == s[j]) ? counts[i - 1] + 1 : 1;
            if (counts[i] == k) i -= k;
        }
        return s.substr(0, i);
    }
};
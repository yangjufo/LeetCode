class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string s = "", res = "a";
        for (auto i = 0; i < strs.size(); ++i) {
            auto r = strs[i];
            reverse(r.begin(), r.end());
            s += max(r, strs[i]);
        }
        for (auto i = 0, st = 0; i < strs.size(); st += strs[i++].size()) {
            auto p1 = strs[i], p2 = strs[i], body = s.substr(st + p1.size()) + s.substr(0, st);
            reverse(p2.begin(), p2.end());
            for (auto j = 0; j < strs[i].size(); ++j) {
                if (p1[j] >= res[0]) res = max(res, p1.substr(j) + body + p1.substr(0, j));
                if (p2[j] >= res[0]) res = max(res, p2.substr(j) + body + p2.substr(0, j));
            }
        }
        return res;
    }        
};
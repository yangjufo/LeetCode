class Solution {
public:
    string simplifyPath(string path) {
        vector<string> ps;
        string curr;
        path += "/";
        for (char c : path) {
            if (c == '/') {
                if (curr == "..") {
                    if (!ps.empty()) {
                        ps.pop_back();
                    }
                } else if (curr == "/" || curr.empty() || curr == ".") {
                } else {
                    ps.push_back(curr);
                }
                curr.clear();
            } else {
                curr += c;
            }
        }
        string res;
        for (string& p : ps) {
            res += "/" + p;
        }
        return res.empty() ? "/" : res;
    }
};
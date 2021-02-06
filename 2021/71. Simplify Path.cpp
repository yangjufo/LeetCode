class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        string sPath, tmp;
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/') {                
                if (tmp == "..") {
                    sPath.pop_back();
                    while (!sPath.empty() && sPath.back() != '/') {
                        sPath.pop_back();
                    }                    
                } else if (!tmp.empty() && tmp != ".") {
                    sPath += tmp + "/";
                }
                cout << tmp << " " << sPath << endl;
                tmp.clear();
                if (sPath.empty()) sPath = "/";
            } else {
                tmp += path[i];
            }
        }
        sPath.pop_back();
        return sPath.empty() ? "/" : sPath;
    }
};
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string realS, realT;
        for (char c: S) {
            if (c == '#') {
                if (!realS.empty())
                    realS.pop_back();
            } else {
                realS += c;
            }            
        }
        for (char c : T) {
            if (c == '#') {
                if (!realT.empty())
                    realT.pop_back();
            } else {
                realT += c;
            }
        }
        return realS == realT;
    }
};
class Solution {
public:
    string removeDuplicates(string S) {
        bool find = true;
        while (find && !S.empty()) {
            find = false;
            for (int i = 0; i < S.length() - 1; i++) {
                if (S[i] == S[i + 1]) {
                    find = true;
                    S = S.substr(0, i) + S.substr(i + 2);
                    break;
                }                    
            }
        }
        return S;
    }
};
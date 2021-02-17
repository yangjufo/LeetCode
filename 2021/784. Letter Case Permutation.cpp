class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> curr;
        curr.push_back("");
        for (int i = 0; i < S.length(); i++) {
            vector<string> tmp;            
            for (string& c : curr) {
                tmp.push_back(c + S[i]);
                if (S[i] >= 'a' && S[i] <= 'z') {                    
                    tmp.push_back(c + string(1, S[i] + 'A' - 'a'));
                }
                if (S[i] >= 'A' && S[i] <= 'Z') {
                    tmp.push_back(c + string(1, S[i] + 'a' - 'A'));
                }
            }
            curr = tmp;
        }
        
        return curr;        
    }
};
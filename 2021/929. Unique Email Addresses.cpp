class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> eSet;        
        for (string& e : emails) {
            bool domain = false, plus = false;
            string key;            
            for (char c : e) {
                if (domain || (c != '@' && !plus && c != '.' && c != '+')) {
                    key += c;
                } else {
                    if (c == '@') {
                        key += c;
                        domain = true;
                    } else if (c == '+') {
                        plus = true;
                    }
                }                
            }       
            eSet.insert(key);
        }
        return eSet.size();
    }
};
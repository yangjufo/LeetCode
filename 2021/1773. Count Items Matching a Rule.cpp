class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0, index = 0;
        if (ruleKey == "type") {
            index = 0;
        } else if (ruleKey == "color") {
            index = 1;
        } else {
            index = 2;
        }
        
        for (vector<string>& item : items) {
            if (item[index] == ruleValue) count++;
        }        
        return count;
    }
};
class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> nums;
        string num;        
        for (int i = 0; i < word.length(); i++) {
            if (isdigit(word[i])) {
                num += word[i];                
            } else {
                if (num.length() > 0) {
                    int i = 0;
                    while (i < num.length() && num[i] == '0') {
                        i++;
                    }
                    nums.insert(num.substr(i));
                }
                num.clear();
            }            
        }
        if (!num.empty()) {
             int i = 0;
            while (i < num.length() && num[i] == '0') {
                i++;
            }
            nums.insert(num.substr(i));
        }
        return nums.size();
    }
};
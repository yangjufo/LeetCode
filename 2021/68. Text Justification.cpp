class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int start = 0, wordLen = 0, wordCount = 0;
        for (int i = 0; i < words.size(); i++) {                                 
            if (wordLen + words[i].length() + wordCount >= maxWidth) {                
                int end = i - 1;
                if (wordLen + words[i].length() + wordCount == maxWidth) {
                    end = i;
                    wordLen += words[i].length();
                    wordCount++;
                }
                int space = (wordCount == 1)
                    ? maxWidth - wordLen
                    : (maxWidth - wordLen) / (wordCount - 1);
                int extra = (wordCount == 1)
                    ? start
                    : (maxWidth - wordLen) % (wordCount - 1) + start;
                string one;
                for (int j = start; j < end; j++) {
                    one += words[j] + string(space, ' ') + ((j < extra) ? " " : "");
                }
                one += words[end] + string(maxWidth - one.length() - words[end].length(), ' ');
                ans.push_back(one);
                if (end == i) {
                    start = i + 1;
                    wordCount = 0;
                    wordLen = 0;
                } else {
                    start = i;
                    wordCount = 1;
                    wordLen = words[i].length();
                }
            } else {
                wordLen += words[i].length();
                wordCount++;
            }
        }
        
        if (start < words.size()) {
            string one;
            for (int j = start; j < words.size(); j++) {
                one += words[j];
                if (j < words.size() - 1) {
                    one += " ";
                }
            }
            one += string(maxWidth - one.length(), ' ');
            ans.push_back(one);
        }
        return ans;
    }
};
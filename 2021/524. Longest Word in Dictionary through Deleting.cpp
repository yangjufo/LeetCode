class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        vector<int> indexes(d.size(), 0);
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < d.size(); j++) {
                if (indexes[j] < d[j].length() && s[i] == d[j][indexes[j]]) {
                    indexes[j]++;
                }
            }
        }
        
        string longestWord;
        for (int i = 0; i < d.size(); i++) {
            if (indexes[i] == d[i].length() && (d[i].length() > longestWord.length() || (d[i].length() == longestWord.length() && d[i] < longestWord))) {
                longestWord = d[i];
            }
        }            
        return longestWord;
    }
};

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {        
        int maxIndex = -1;
        for (int di = 0; di < d.size(); di++) {
            string sub = d[di];
            int i = 0;
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == sub[i]) i++;
            }            
            if (i >= sub.length() && (maxIndex == -1 || (sub.length() > d[maxIndex].length() || (d[maxIndex].length() == sub.length() && sub < d[maxIndex])))) {
                maxIndex = di;
            }
        }        
        
        return maxIndex == -1 ? "" : d[maxIndex];
    }
};
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int index = 0;
        string res;
        for (int i = 0; i < s.length(); i++) {
            if (index < spaces.size() && i == spaces[index]) {
                res += " ";
                index++;
            }
            res += s[i];
        }
        return res;
    }
};
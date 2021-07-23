class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            int j = 0;            
            while (j < words.size() && j < words[i].length() && i < words[j].length() && words[i][j] == words[j][i]) {
                j++;
            }       
            if (!(j >= words[i].length() && (j >= words.size() || i >= words[j].length()))) {
                return false;
            }
        }
        return true;
    }
};
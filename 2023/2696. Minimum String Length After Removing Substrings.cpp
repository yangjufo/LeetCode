class Solution {
public:
    int minLength(string s) {
        bool found = true;
        string result = s;
        while (found) {
            found = false;
            string tmp;
            int i = 0;
            while (i < result.length()) {
                if (result[i] == 'A' && result[i + 1] == 'B') {
                    i += 2;
                    found =true;
                    continue;
                }
                if (result[i] == 'C' && result[i + 1] == 'D') {
                    i += 2;
                    found = true;
                    continue;
                }
                tmp += result[i];
                i++;
            }
            result = tmp;
        }
        return result.length();
    }
};
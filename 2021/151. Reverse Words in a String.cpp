class Solution {
public:
    string reverseWords(string s) {
        string tmp, ans;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!tmp.empty()) {
                    ans += reverse(tmp) + ' '; 
                } 
                tmp = "";
            } else {
                tmp += s[i];
            }
        }
        if (!tmp.empty()) {
            ans += reverse(tmp);
        } else if (!ans.empty()) {
            ans = ans.substr(0, ans.length() - 1);
        }
        return reverse(ans);
    }
    
    string reverse(string str) {
        int left = 0, right = str.length() - 1;
        while (left < right) {
            int c = str[left];
            str[left] = str[right];
            str[right] = c;
            left++;
            right--;
        }
        return str;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        string ans = s, tmp;
        int index = s.length() - 1;
        s += ' ';
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!tmp.empty()) {
                    for (int j = tmp.length() - 1; j >= 0; j--) {
                        ans[index] = tmp[j];
                        index--;
                    }
                    if (index >= 0) {
                        ans[index] = ' ';
                    }                    
                    index--;
                }
                tmp = "";
            } else {
                tmp += s[i];
            }
        }       
        return ans.substr(index + 2);
    }
};
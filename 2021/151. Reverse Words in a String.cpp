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


class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {                
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }            
        reverse(s.begin() + start, s.end());
        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ' || (index != 0 && s[index - 1] != ' ')) {
                s[index] = s[i];
                index++;
            }            
        }        
        if (index > 0 && s[index - 1] == ' ') {
            index--;
        }
        return s.substr(0, index);
    }
};
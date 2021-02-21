class Solution {
public:
    int romanToInt(string s) {
        int num = 0;        
        int i = 0;
        for (int i = 0; i < s.length(); i++) {
            int curr = 0;            
            switch(s[i]) {
                case 'I':
                    if (i < s.length() - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                        curr = -1;
                    } else {
                        curr = 1;
                    }
                    break;
                case 'V':
                    curr = 5;
                    break;
                case 'X':
                    if (i < s.length() - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                        curr = -10;
                    } else {
                        curr = 10;
                    }
                    break;
                case 'L':
                    curr = 50;
                    break;
                case 'C':
                    if (i < s.length() - 1 && s[i + 1] == 'D' || s[i + 1] == 'M') {
                        curr = -100;
                    } else {
                        curr = 100;
                    }
                    break;
                case 'D':
                    curr = 500;
                    break;
                case 'M':
                    curr = 1000;
                    break;
            }
            num += curr;
        }
        return num;
    }
};


class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case 'M':
                    num += 1000;
                    break;
                case 'D':
                    num += 500;
                    break;
                case 'C':
                    num += (i < s.length() - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M')) ? -100 : 100;
                    break;
                case 'L':
                    num += 50;
                    break;
                case 'X':
                    num += (i < s.length() - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C')) ? -10 : 10;
                    break;
                case 'V':
                    num += 5;
                    break;
                case 'I':
                    num += (i < s.length() - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X')) ? -1: 1;
                    break;
                default:
                    break;
            }            
        }
        return num;
    }
};
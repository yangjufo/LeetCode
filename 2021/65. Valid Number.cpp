class Solution {
public:
    bool isNumber(string s) {
        bool numFound = false;
        bool eFound = false;
        bool dotFound = false;
        bool spaceAllowed = true;
        bool spaceFound = false;
        bool signFound = false;
        for (int i = 0; i < s.length(); i++) {                 
            while (s[i] == ' ') {
                spaceFound = true;
                i++;
            }
            if (i == s.length()) break;            
            if (spaceFound) {
                if (!spaceAllowed) return false;                
                spaceFound = false;
            }
            spaceAllowed = false;
            if (isdigit(s[i])) {                
                numFound = true;
            } else if (s[i] == '-' || s[i] == '+') {                
                if (numFound || dotFound || signFound) return false;
                signFound = true;
            } else if (s[i] == 'e') {                
                if (!numFound || eFound) return false;
                eFound = true;
                numFound = false;
                dotFound = false;
                signFound = false;
            } else if (s[i] == '.') {
                if (dotFound || eFound) return false;                
                dotFound = true;
            } else {
                return false;
            }
        }
        return numFound;
    }
};

class Solution {
public:
    bool isNumber(string s) {
        bool digitFound = false, dotFound = false, eFound = false, signFound = false;
        for (char c : s) {            
            if (isdigit(c)) {
                digitFound = true;
            } else if (c == '+' || c == '-') {
                if (signFound || digitFound || dotFound) return false;
                signFound = true;
            } else if (c == '.') {
                if (dotFound || eFound) return false;
                dotFound = true;
            } else if (c == 'e' || c == 'E') {
                if (eFound || !digitFound) return false;
                eFound = true;
                signFound = digitFound = dotFound = false;
            } else {
                return false;
            }
        }
        return digitFound;
    }
};
class Solution {
public:
    vector<char> toHexChar = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    string toHex(int num) {        
        if (num == 0) return "0";        
        string result;
        while (num != 0){
            result = toHexChar[num&15] + result;
            num = (unsigned int) num >> 4;
        }
        return result;
    }
};

class Solution {
public:
    vector<char> toHexChar = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    string toHex(int num) {        
        if (num == 0) return "0";
        string res;
        while (num != 0) {
            res += toHexChar[num & 0xF];
            num = (unsigned) num >> 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
class Solution {
public:
    int romanToInt(string s) {        
        char Rom_num[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int last_Rom[7];
        int res = 0;
        for (int i = 0; i < 7; i++)
            last_Rom[i] = s.find_last_of(Rom_num[i]);
        for (int i = 0; i < s.length(); i++){
            switch(s[i]){
                case 'M':
                    res += 1000;
                    break;
                case 'D':
                    res += 500;
                    break;
                case 'C':
                    if (i < last_Rom[0] || i < last_Rom[1])
                        res -= 100;
                    else
                        res += 100;
                    break;
                case 'L':
                    res += 50;
                    break;
                case 'X':
                    if (i < last_Rom[2] || i < last_Rom[3])
                        res -= 10;
                    else
                        res += 10;
                    break;
                case 'V':
                    res += 5;
                    break;
                case 'I':
                    if(i < last_Rom[4] || i < last_Rom[5])
                        res -= 1;
                    else
                        res += 1;
                    break;
                default:
                    break;
                        
            }
        }
        return res;        
    }
};
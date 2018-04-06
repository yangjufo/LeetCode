class Solution {
public:
    string intToRoman(int num) {        
        int tmp_count;
        string res;        
        tmp_count = num / 1000;
        if (tmp_count != 0)
            res += string(tmp_count, 'M');
        num %= 1000;
        tmp_count = num / 100;
        if (tmp_count == 9)
            res += "CM";
        else if(tmp_count == 4)
            res += "CD";
        else if(tmp_count >= 5)
            res += "D" + string(tmp_count - 5, 'C');
        else if (tmp_count != 0)
            res += string(tmp_count, 'C');
        num %= 100;
        tmp_count = num / 10;
        if (tmp_count == 9)
            res += "XC";
        else if (tmp_count == 4)
            res += "XL";
        else if (tmp_count >= 5)
            res += "L" + string(tmp_count - 5, 'X');
        else if (tmp_count != 0)
            res += string(tmp_count, 'X');
        tmp_count = num % 10;
        if (tmp_count == 9)
            res += "IX";
        else if (tmp_count == 4)
            res += "IV";
        else if (tmp_count >= 5)
            res += "V" + string(tmp_count - 5, 'I');
        else if (tmp_count != 0)
            res += string(tmp_count, 'I');                
          return res;
    }
};